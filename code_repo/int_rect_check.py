'''
	Author - Vikas Rao
	Usage - *.py *.blif <num_of_targets> <bug_config>
	
	cofac*.log - output with target names and remainders generated
	{on,off} - use either on-set for computation or off-set for computation
	{0,1} - 0 - no sis_synthesis of don't cares
			1 - perform don't care simplification using sis

	Approach:

	For every cofactor (remainder):
	Create eqn by reading functions from cofac*.log (2^n functions)
	Read in abc - write it out as blif (unmapped)
	Rename all intermediate nodes using a distinct notation
	As and when you generate blifs - merge it into respective single files
		gfch - greedy function blif file
		dfch - don't care computation blif file

	In GFC:
	Add lines related to Union/intersection and set difference
	Synthesize using abc

	In DFC:
	Add lines related to Union/intersection and set difference
	If possible, synthesize using sis and then with abc
	Else synthesize using abc

	Blif logic:
	for Boolean sets (on-set/off-set/DC-set)
	Union - 00 0
	Intersection - 11 1
	Diff (A-B) - 10 1

	for polynomial functions
	Union - 11 1
	Intersection - 00 0
	Diff (A-B) - 01 0
'''
import sys
import re
import os
import subprocess
import time
import pdb
# import threading
# import func_computation
# from collections import defaultdict, deque


# from utilities import *

abc_synth = False
pdebug = False
use_singular = True
use_singular_for_poly_mult = True

delete_cof_files = True
delete_tmp_files = True
src_path   = '../../'
rcheck_dir = 'rect_check/'

########################################################################################
##################### Time stamp for overall procedures ###################
########################################################################################
def print_overall_time(  	tm_bugp='N/A',
				 			tm_remgen='N/A',
				 			tm_setup_poly='N/A',
				 			tm_singular_comp='N/A',
				 			tm_func_comp='N/A'):

	logFile.write('\n--------- Time Data -----------------\n')
	logFile.write('create bugs + setup time(processing)	  {}\n'.format(round(tm_bugp+tm_setup_poly,1)))
	logFile.write('Total time for remainder generation 	  {}\n'.format(round(tm_remgen,1)))
	logFile.write('Total time for singular computation	  \t{}\n'.format(round(tm_singular_comp,1)))
	logFile.write('Total time for function computation	  \t{}\n'.format(round(tm_func_comp,1)))
	logFile.write('Total time:                  		  \t{}\n'.format(round(tm_bugp+tm_setup_poly+tm_remgen+tm_singular_comp+tm_func_comp,1)))
	logFile.write('----------- Time Data -----------------\n')

########################################################################################
##################### Time stamp for function computation procedures ###################
########################################################################################
def print_time(tm_abc_aig='N/A',
				 tm_set='N/A',
				 tm_setg='N/A',
				 tm_setd='N/A',
				 tm_gfcs='N/A',
				 tm_sdfcs='N/A',
				 tm_adfcs='N/A'):

	print '\n------------------- Time Data -------------------'
	print 'create aigs using abc             			', round(tm_abc_aig,1)
	print 'Total setup time for gfc files 				', round(tm_set+tm_setg,1)
	print 'Total setup time for dfc files 				', round(tm_set+tm_setd,1)
	print 'Synthesizing gfc files using abc: 			', round(tm_gfcs,1)
	print 'Synthesizing dfc files using sis: 			', round(tm_sdfcs,1)
	print 'Synthesizing postSIS - dfc files using abc:		', round(tm_adfcs,1)
	print 'Total gfc time:                  			', round(tm_set+tm_setg+tm_gfcs,1)
	print 'Total dfc time:                  			', round(tm_set+tm_setd+tm_adfcs+tm_sdfcs,1)
	print '------------------- Time Data -------------------\n'

###################################################################
######################## Global declarations ######################
###################################################################

tm_st = time.time()
tm_total = time.time()
tm0 = time.time()

curr_wd = os.getcwd()

total_args = len(sys.argv)-1
expctd_args = 5
inps = []
outps = []
rs = 'rg'

cofac_synth = ''

if (total_args < expctd_args):
	print ("Expected {} input argument file(s)!!".format(expctd_args))
	sys.exit(0)
else:
	fileInput     = sys.argv[1]
	num_trgts     = int(sys.argv[2])
	bug_config    = int(sys.argv[3])
	use_tool      = sys.argv[4]
	rand_bug      = sys.argv[5]
	dirName       = os.path.dirname(fileInput)
	baseFile      = os.path.basename(fileInput)
	os.chdir('{}/{}/'.format(curr_wd,dirName))
	try:
		blifFile = open(baseFile,'r')
	except IOError:
		print ("Couldn't read the input file using handler!!")
		sys.exit(0)

if rand_bug == '1':
	random_bug = True
else:
	random_bug = False

curr_wd = os.getcwd()
use_revsca   = False
use_amulet10 = False
use_amulet15 = False
use_amulet20 = False


# if use_tool == 'amulet10':
# 	use_amulet10 = True
if use_tool not in ['amulet15','amulet20','revsca']:
	print("Not a valid tool option !! Allowed options are - ['amulet15','amulet20','revsca']")
	sys.exit(0)

if use_tool == 'amulet15':
	use_amulet15 = True
elif use_tool == 'amulet20':
	use_amulet20 = True
elif use_tool == 'revsca':
	use_revsca = True
else: #use the current default stable tool
	use_amulet15 = True

#baseFileName
bfName = baseFile.strip('.blif')

#open a log file for tracking model info and bug info
logFile  = '{}.log'.format(bfName)
remFile  = 'rem_{}.log'.format(bfName)
rcFile   = 'rc_{}.cpp'.format(bfName)
siFile   = 'rc_{}.sing'.format(bfName)
cofacLog = 'cofac_{}.log'.format(bfName)

inp_frmt = ''

try:
	logFile = open(logFile,'w')
except IOError:
	print ("Couldn't open log file for writing!!")
	sys.exit(0)

'''
Utility functions
'''
def read_a_line(fhandle):

	#Handle empty lines with all kinds of spaces
	line = fhandle.readline()
	if (line):
		if line.rstrip():
			return line.strip().strip(';\\')
		else:
			return read_a_line(fhandle)

def check_bnchmrk_format(inpStr):

	return {
		'IN1[0]':"Aoki format - Input:{},Output:{}".format(inps[1],outps[1]) ,
		'a0':"abc format - Input:{},Output:{}".format(inps[1],outps[1]),
		'pi00':"Another abc format - Input:{},Output:{}".format(inps[1],outps[1]),
		'a[0]':"Btor format - Input:{},Output:{}".format(inps[1],outps[1]),
	}[inpStr]

def set_input_format(inpStr):
	return {
		'IN1[0]':'IN',
		'a0':'a',
		'pi00':'pi',
		'a[0]':'a[',
	}[inpStr]

def strip_last_x_lines(x):
	global pos
	for _ in range(x+1):
		while pos > 0 and pFH.read(1) != "\n":
			pos -= 1
			pFH.seek(pos, os.SEEK_SET)

	if pos > 0:
		pFH.seek(pos, os.SEEK_SET)
		pFH.truncate()

def write_abc_aig_cofac_gen_script():

	tmp = open('abc_gen_aig_cofacs.script','w')
	tmp.write('read {}cadence_abc.genlib\n'.format(src_path))
	tmp.write('source {}abc.rc\n'.format(src_path))
	tmp.write('read_blif {};\n'.format(pFile))
	tmp.write('strash;\n')
	# if use_tool == 'revsca': 
	# 	tmp.write('fraig;\n')
	# 	tmp.write('resyn;resyn2;\n')
	# tmp.write(cofac_synth)
	tmp.write('write_aiger {}.aig;quit;\n'.format(pName))

	tmp.close()

def escape_ansi(line):
	ansi_escape =re.compile(r'(\x9B|\x1B\[)[0-?]*[ -\/]*[@-~]')
	return ansi_escape.sub('', line)

def process_revsca_output():

	remlog = open(remFile,'a')
	facCount = 0

	with open('rev_sca.out','r') as rlog:
		for cline in rlog:
			cline = cline.strip().rstrip()
			if cline:
				if ((cline[0]  == '*') or ('Remainder' in cline) or('buggy' in cline)):
					pass
				elif (cline[2:7] == '1;37m'): 
					remlog.write(escape_ansi(cline) + '\n')
					facCount += 1
				elif ('correct' in cline):
					remlog.write('CORRECT\n')

	remlog.close()

	assert(facCount == 2**num_trgts)

def split_revsca_polynomial(polynomial):

	polyList = polynomial.split('+')

	terms = [['0' for x in range(2)] for y in range(len(polyList))]

	for idx in range(len(polyList)):
		# print("for poly: {}".format(polyList[idx]))
		coeff = polyList[idx].strip().split('\xc3\x97',1)
		# print("coeff:{}".format(coeff))
		terms[idx][0] = coeff[0].strip()
		if (len(coeff) == 2):
			terms[idx][1] = coeff[1].strip()

		del coeff

	return terms 

def write_poly_mul_script_for_amulet():

	logFile.write("*** Generating rectification check file for amulet *** \n\n")
	
	f1 = 'decl.log'
	f2 = 'poly.log'
	f3 = 'cleanup.log'
	#Variable/monomial/term declarations and building
	pm =  open(f1,'w')
	#polynomial generation and multiplication file
	pl =  open(f2,'w') 
	#file to write the monom/term/poly delete lines which are appended to main file
	dl =  open(f3,'w') 

	#delete the old cpp file 
	subprocess.call(['rm -rf {}'.format(rcFile)],stdout=logFile,shell=True,cwd=os.getcwd())

	#Final cpp file with all the above files merged
	pmf =  open('{}'.format(rcFile),'w')
	pmf.close()

	pm.write("\n#include \"includes/polynomial.h\"\n")
	pm.write("int main(){\n\n")

	orderNum = 2*bitWidth 
	for idx in range(bitWidth-1,-1,-1):
		pm.write("\tVar * b{0} = new Var(\"b{0}\",{1});\n".format(idx,orderNum))
		orderNum -= 1

	for idx in range(bitWidth-1,-1,-1):
		pm.write("\tVar * a{0} = new Var(\"a{0}\",{1});\n".format(idx,orderNum))
		orderNum -=1

	assert(orderNum == 0)

	pm.write("\tmpz_t coeff;\n")
	pm.write("\tmpz_init_set_ui(coeff,1);\n\n")
	# Read the cofactor remainder file generated from amulet
	try:
		rl = open(remFile,'r')
	except IOError:
		print ("Couldn't open the remainder file for reading!!")
		sys.exit(0)

	# Build terms and polynomials
	line = rl.readline()
	t_map = set()
	m_map = set()
	
	#Constant -1 poly to perform multiplication at every step
	p_str = "mul_0"
	mhash = abs(hash('1'+''))
	m_str = "m_{}".format(mhash)
	pm.write("\tmpz_set_ui(coeff,1);\n")
	pm.write("\tMonomial * {} = new Monomial (coeff,0);\n\n".format(m_str))
	pm.write("\tpush_mstack({}->copy());\n".format(m_str))
	pm.write("\tPolynomial * {} = build_poly();\n".format(p_str))
	# p_map[0].append(mhash)
	for cofac in range(2**num_trgts):
		line = rl.readline().strip().strip(';')
		if (line[0:8] == "CORRECT"):
			logFile.write("Constant assignment {} to the targets rectifies the circuit".format(bin(cofac)[2:].zfill(num_trgts)))
			# cleanup()
			sys.exit(0)


		polynomial = line.strip()
		if (use_tool == 'revsca'):
			terms = split_revsca_polynomial(polynomial)
			termRange = len(terms)
		else:
			terms = re.findall(r'([-+]?\d*)([ab\d*\*]*)',polynomial)
			termRange = len(terms)-1

		p_str = "p_{}".format(cofac)
		for idx in range(termRange): # Last term is dummy due to null character
			# pdb.set_trace()
			# terms[idx][0] = coefficient 
			# terms[idx][1] = corresponding monomial
			# cofac - index for remainder (00 - rem_00, 01- rem_01, 10 - rem_10 ... so on)
			# idx  - index for each term in the polynomial of a given remainder
			mhash = abs(hash(terms[idx][0]+terms[idx][1]))
			m_str = "m_{}".format(mhash)

			if (mhash not in m_map):

				is_copy = False
				thash = abs(hash(terms[idx][1]))
				t_str = "t_{}".format(thash)		
				
				#build monomial - check if monomial exists - 
				# also presuming a collision free hashing (hence - using double hashing)
				if (thash in t_map):
					is_copy = True
					t_str += "->copy()"
				else:
					if (terms[idx][1]):
						if (use_tool != 'revsca'):
							t_vars = terms[idx][1].lstrip("*").split("*")

							for varbl in t_vars:
								pm.write("\tadd_to_vstack({});\n".format(varbl))
						else:
							t_vars = terms[idx][1].split('\xc3\x97')
							for varbl in t_vars:
								if varbl:
									vidx = int(varbl)
									if (vidx <= bitWidth):
										pm.write("\tadd_to_vstack(a{});\n".format(vidx-1))
									else:
										pm.write("\tadd_to_vstack(b{});\n".format(vidx-1-bitWidth))
						pm.write("\tTerm * {} = build_term_from_stack();\n\n".format(t_str))


				if (terms[idx][0][0] == '-'):
					if (terms[idx][0] == '-'): # When no coefficient integer but just monom
						pm.write("\tmpz_set_si(coeff,-1);\n")
					else: 
						pm.write("\tmpz_set_si(coeff,{});\n".format(terms[idx][0]))
				elif (terms[idx][0][0] == '+'):
					if (terms[idx][0] == '+'):
						pm.write("\tmpz_set_ui(coeff,1);\n")
					else:
						pm.write("\tmpz_set_ui(coeff,{});\n".format(terms[idx][0].strip('+')))
				else:
					if (terms[idx][0]):
						pm.write("\tmpz_set_ui(coeff,{});\n".format(terms[idx][0]))
					else:
						pm.write("\tmpz_set_ui(coeff,1);\n")
				
				if (terms[idx][1]):
					pm.write("\tMonomial * {} = new Monomial (coeff,{});\n\n".format(m_str,t_str))
				else:
					pm.write("\tMonomial * {} = new Monomial (coeff,0);\n\n".format(m_str))

				del terms
				t_map.add(thash)
				m_map.add(mhash)

				dl.write("\tdelete({});\n".format(m_str))
			pl.write("\tpush_mstack({}->copy());\n".format(m_str))
			# p_map[cofac+1].append(mhash)

		# pdb.set_trace()

		pl.write("\tPolynomial * {} = build_poly();\n\n".format(p_str))

		#Code to multiply polynomials
		pl.write("\tfprintf(stdout, \"Multiplying mul_{} and {} yields:\\n\");\n".format(cofac,p_str))
		pl.write("\tPolynomial * mul_{} = multiply_poly(mul_{},{});\n".format(cofac+1,cofac,p_str))
		pl.write("\tmul_{}->print(stdout);fprintf(stdout,\"\\n\");\n".format(cofac+1))
		pl.write("\tdelete(mul_{});delete({});\n\n".format(cofac,p_str))
		
		if (cofac == (2**num_trgts-1)):
			pl.write("\tif(mul_{0} && !mul_{0}->is_constant_zero_poly())\n".format(cofac+1))
			pl.write("\t\tfprintf(stdout,\"Non-zero remainder ! Rectification not possible !!\\n\");\n")
			pl.write("\telse\n")
			pl.write("\t\tfprintf(stdout,\"Zero remainder ! Rectification possible !!\\n\");\n\n")
			pl.write("\tdelete(mul_{0});\n".format(cofac+1))

		# subset_sum = compute_subset_sum_from_terms(terms)
		# construct_an_equivalent_boolean_poly(subset_sum)

	# Delete hash sets and maps 
	del t_map
	del m_map
	# del p_map

	#Delete polynomial objects
	# for cofac in range(2**num_trgts+1):
	# 	pl.write("\tdelete(p_{});\n".format(cofac))
	
	pl.close()
	dl.write("\tdeallocate_terms();deallocate_mstack();mpz_clear(coeff);\n")
	# pdb.set_trace()	

	#Delete variable objects
	for idx2 in range(bitWidth-1,-1,-1):
		dl.write("\tdelete(b{0});delete(a{0});\n".format(idx2))
	
	dl.write("\treturn 0;\n}")
	dl.close()
	pm.close()

	#Merge all three files using shell and then delete them
	cmd = 'cat {0} {1} {2} > {3};rm {0} {1} {2};'.format(f1,f2,f3,rcFile)
	subprocess.call([cmd],shell=True,cwd=os.getcwd())

	logFile.write("*** Rectification check file generated *** \n")


# def compute_subset_sum_from_terms(terms):

# 	'''
# 		Check coefficients of each term in terms and
# 		compute a set of sets where the sum of all
# 		coefficients within a subset is equal to 0.
# 		Which implies, that their corresponding monomials
# 		need to evaluate to 1 for that point to be in the variety.
# 		And the rest of the monomials have to evaluate to 0.
# 	'''
# 	pass

def run_rect_check_using_polylib():

	#Merge all three files using shell and then delete them
	cmd = 'cp {0} {1}demo_polylib.cpp;cd {1};make clean; sh ./configure.sh; make;./demo;cd ..;'.format(rcFile,rcheck_dir)
	subprocess.call([cmd],stdout=logFile,shell=True,cwd=os.getcwd())
	logFile.write("*** Rectification check done *** \n")


def write_poly_script_for_singular():

	logFile.write("*** Generating rectification check file for Singular *** \n\n")
	
	#Final cpp file with all the above files merged
	pmf =  open('{}'.format(siFile),'w')

	pmf.write("\nLIB \"{}my_proc.lib\";\n\nring r1 = 0, (".format(src_path))
	rstr = ''
	j0 = 'ideal J0 = '
	for idx in range(bitWidth):
		rstr += "a{},".format(idx)
		j0 += 'a{0}^2-a{0},'.format(idx)

	for idx in range(bitWidth):
		rstr += "b{},".format(idx)
		j0 += 'b{0}^2-b{0},'.format(idx)

	pmf.write('{}),dp;\n\n'.format(rstr[:-1]))
	pmf.write('{};\n\n'.format(j0[:-1]))
	pmf.write('poly tmp_0 = 1;\n')

	del rstr
	del j0

	# Read the cofactor remainder file generated from amulet
	try:
		rl = open(remFile,'r')
	except IOError:
		print ("Couldn't open the remainder file for reading!!")
		sys.exit(0)

	# Build terms and polynomials
	line  = rl.readline()
	t_map = set()
	m_map = set()
	s_list = '\tlist poly_list = '
	d_list = '\tlist polyb_list = '
	gb_poly = ''
	for cofac in range(2**num_trgts):
		line = rl.readline().strip().strip(';')
		if (line[0:8] == "CORRECT"):
			logFile.write("Constant assignment {} to the targets rectifies the circuit".format(bin(cofac)[2:].zfill(num_trgts)))
			# cleanup()
			sys.exit(0)

		p_str  = "p_{}".format(cofac)
		polynomial = line.strip()
		if (use_tool != 'revsca'):
			pmf.write("poly {}={};\n".format(p_str,polynomial))
		else:
			terms = split_revsca_polynomial(polynomial)
			term = "poly {}=".format(p_str)
			for idx in range(len(terms)): 
				# terms[idx][0] = coefficient 
				# terms[idx][1] = corresponding monomial
				# cofac - index for remainder (00 - rem_00, 01- rem_01, 10 - rem_10 ... so on)
				# idx  - index for each term in the polynomial of a given remainder
				term += terms[idx][0]
				if (terms[idx][1] != '0'):
					t_vars = terms[idx][1].split('\xc3\x97')
					for varbl in t_vars:
						if varbl:
							vidx = int(varbl)
							if (vidx <= bitWidth):
								term += "*a{}".format(vidx-1)
							else:
								term += "*b{}".format(vidx-1-bitWidth)
				term += '+'
			pmf.write("{};\n".format(term[:-1]))

					
		#Code to multiply polynomials
		pmf.write('poly tmp_{0} = reduce(tmp_{1}*p_{1},J0);\n'.format(cofac+1,cofac))
		pmf.write('\"Multiplication-{} done\";\n'.format(cofac))

		gb_poly += '\tpoly pb_{0} = id2poly_int(reduce(slimgb(p_{0}+J0),J0)+0,J0);\n\"\tgb computation-{0} done\";\n'.format(cofac)
		s_list += 'pb_{},'.format(cofac)
		d_list += '0,'
	
	pmf.write("if ( tmp_{} != 0){{\n\t\"Rectification doesn't exist\";\n\tquit;\n}}".format(2**num_trgts))
	pmf.write("else{\n\t\"Rectification exists\";\n")
	pmf.write("\toption(redSB);\n")
	pmf.write("{}\n".format(gb_poly))
	pmf.write("{};\n".format(s_list[:-1]))
	pmf.write("{};\n".format(d_list[:-1]))
	pmf.write("\tfor (int j=1;j<=size(poly_list);j++){\n")
	pmf.write("\t\tfor (int i=1;i<=size(poly_list[j]);i++){\n")
	pmf.write("\t\t\tint coeff = int(leadcoef(poly_list[j][i]))%2;\n")
	pmf.write("\t\t\tif (coeff == -1 or coeff == 1){\n")
	pmf.write("\t\t\t\tpolyb_list[j] = polyb_list[j] + leadmonom(poly_list[j][i]);\n")
	pmf.write("\t\t\t}\n\t\t}\n\tpolyb_list[j];\n\t}\n}\nquit;")

	pmf.close()

	logFile.write("*** Rectification check file generated for singular*** \n")

def compute_rc_and_boolrem_using_singular():

	#Merge all three files using shell and then delete them
	cmd = 'Singular --no-warn -q {} > {}'.format(siFile,cofacLog)
	print("*** Starting singular computations *** \n")
	subprocess.call([cmd],stdout=logFile,shell=True,cwd=os.getcwd())
	logFile.write("*** Rectification check done *** \n")
	print("*** Singular computations done *** \n")

def check_if_rect_exists():

	# clog = open("{}".format(cofacLog),'r')
	# cline = clog.readline()
	# print(cline)
	with(open("{}".format(cofacLog),'r')) as clog:
		cline = clog.readline()

	# clog.close()
	if (cline == 'Rectification exists'):
		return True
	else:
		return False

def write_inputs(f):
	for idx in range(bitWidth):
		f.write("a{} ".format(idx))

	for idx in range(bitWidth):
		f.write("b{} ".format(idx))

def compute_functions():


	# Proceeding to analyze cofactor log file to compute the MFR patches.
	# Write the ON-set and OFFC-set files from .
	# bnchmrk_dtls = read_a_line(log).split()

	# #Verify bench mark details again
	# bnch_mark = (bnchmrk_dtls.pop(0))
	# bw = int(bnchmrk_dtls.pop(0))
	# fw = int(bnchmrk_dtls.pop(0))
	tm0 = time.time()
	gfc_computation = True
	dfc_computation = True

	sis_synth = False
	sis_synth_dfc = True
	abc_synth = False

	trgts = targetstr.split()
	fw = len(trgts)
	bw = bitWidth
	fstr = 'on'
	svstr = '1'
	synth_config = 1
	sis_dfc = True

	#  By default use on-set for computation
	comp_using_offset = False
	# If specified, use off-set for computation
	# if use_set == 'off':
	# 	comp_using_offset = True
	# 	fstr = 'off'
	# 	svstr = '0'
	# else:
	# 	fstr = 'on'
	# 	svstr = '1'
	'''
	Configuration settings
	'''
	# class config:

	# 	def __init__():
	# 		self.cofac_synth = ''
	# 		self.synth_str = ''
	# 		self.sis_synth_str = ''

	# 	def mode(synth_config):
	# 	return{
	# 		'1':self.synth_str = synth_str6self.
	# 		'2':['',synth_str6]
	# 		'3':['',synth_str6]
	# 		'4':['',synth_str6]
	# 	}.get(synth_config,'1')

	# synth_str1 = 'resyn; resyn2; resyn3; resyn; dch;\n' #-- 1
	# synth_str2 = 'resyn; resyn2; resyn3; resyn; resyn2rs; dch;\n' #--2
	# synth_str3 = 'resyn; resyn2; resyn3; resyn; resyn2rs; dch; source script_aggr.abc;\n' #--3
	synth_str4 = 'resyn; resyn2; resyn3; dch;\n' #-- 4
	# synth_str5 = 'resyn; resyn2; dch;\n' #-- 5
	synth_str6  = 'fraig;resyn2;dch;\n' #-- 6
	synth_str6a = 'resyn; resyn2; resyn3;dch;source {}script_aggr.abc;\n'.format(src_path) #-- 6
	synth_str7 = 'resyn2; resyn3; dch;\n' #-- 7
	# synth_str8 = 'resyn; resyn2; resyn3; dch; \n' #-- 8

	#sis_synth_str = 'source iter_script.sis\n'
	sis_synth_str = 'source {}script.rugged\n'.format(src_path)

	if synth_config == '1':#no cofac reduction, nominal abc and aggr sis
		cofac_synth = ''
		# gfc_synth_str = synth_str6 
		# dfc_synth_str = synth_str6 
		gfc_synth_str = '' 
		dfc_synth_str = ''
	elif synth_config == '2': # nominal cofac/abc synth and aggr sis
		cofac_synth = ''
		gfc_synth_str = synth_str6
		dfc_synth_str = synth_str7
	elif synth_config == '3': #  everything aggressive
		cofac_synth = ''
		gfc_synth_str = synth_str6
		dfc_synth_str = synth_str6a
	else:#default with no cofac reduction, nominal abc and aggr sis
		cofac_synth = ''
		gfc_synth_str = synth_str6
		dfc_synth_str = synth_str6

	if sis_dfc == '0':
		sis_synth_dfc = False

	print("Synthesis options:")
	print("Cofactor abc: {}".format(cofac_synth))
	print("target(s) blif gfc abc: {}".format(gfc_synth_str))
	print("target(s) blif dfc abc: {}".format(dfc_synth_str))
	if sis_synth_dfc:
		print("sis: {}".format(sis_synth_str))

	
	cofacsp = []
	cofacsn = []

	log = open("{}".format(cofacLog),'r')
	for _ in range(2**(fw+1)+1):
		cline = log.readline()
	# while 'ation' not in cline:
	# 	cline = log.readline()
	for num_cofacs in range((2**fw)):
		cofac = read_a_line(log)
		if cofac != None:
			if cofac[-1] == '1':
				cofacsp.append('('+cofac[:-2]+')')
			else:
				cofacsp.append('!('+cofac+')')
	# print("cofacsp-{}".format(cofacsp))
	log.close()
	assert(len(cofacsp) == (2**fw))

	tot_sets = len(cofacsp)
	tm_abc_aig = 0.0
	tm_set = 0.0
	tm_setg = 0.0
	tm_setd = 0.0
	tm_gfcs = 0.0
	tm_sdfcs = 0.0
	tm_adfcs = 0.0
	if gfc_computation:

		gfcfile    = 't{}_gfc_{}_{}_{}'.format(fstr,bnch_mark,bw,fw)
		gfch = open('{}.blif'.format(gfcfile),'w')
		gfch.write('# BLIF for all the targets computed using {}-sets of GFC computations\n'.format(fstr))
		gfch.write('.model {}\n.inputs '.format(gfcfile))
		write_inputs(gfch)
		gfch.write('\n.outputs ')

		for target in range(fw):
			gfch.write(trgts[target]+' ')

		gfch.write('\n')

	if dfc_computation:

		dfcfile = 't{}dc_dfc_{}_{}_{}'.format(fstr,bnch_mark,bw,fw)
		dcfile = 'tdc_dfc_{}_{}_{}'.format(bnch_mark,bw,fw)
		dfch = open('{}.blif'.format(dfcfile),'w')
		edcfh = open('{}.blif'.format(dcfile),'w')
		dfch.write('# BLIF for all the targets computed using {}-sets of DFC computations\n'.format(fstr))
		edcfh.write('\n# exdc BLIF for all the targets computed using {}-sets of DFC computations\n'.format(fstr))
		dfch.write('.model {}\n.inputs '.format(dfcfile))
		edcfh.write('.exdc \n.inputs ')
		write_inputs(dfch)
		write_inputs(edcfh)
		dfch.write('\n.outputs ')
		edcfh.write('\n.outputs ')

		for target in range(fw):
			dfch.write(trgts[target]+' ')
			edcfh.write(trgts[target]+' ')
		dfch.write('\n')
		edcfh.write('\n')

	'''
	Cofactor for merging

	'''
	print("\nComputing BLIFS for cofactors\n")
	for cfidx in range(len(cofacsp)):

		copfile = 'cofp_{}_{}_{}_{}'.format(bnch_mark,bw,fw,cfidx)
		cpfh = open('{}.eqn'.format(copfile),'w')
		cpfh.write('INORDER = ')
		write_inputs(cpfh)
		cpfh.write(';\nOUTORDER = cf{} ;\n'.format(cfidx))
		cpfh.write('cf{} = {};'.format(cfidx,cofacsp[cfidx]))
		cpfh.close()

		tmp = open('tmp.txt','w')
		tmp.write('source {}abc.rc\n'.format(src_path))
		tmp.write('read_eqn {}.eqn;\n'.format(copfile))
		tmp.write('strash;\n') 
		tmp.write('fraig;\n')
		tmp.write(cofac_synth)
		tmp.write('write_blif {}.blif;quit;\n'.format(copfile))

		tmp.close()
		subprocess.call(['{}/abc -f tmp.txt  > /dev/null'.format(src_path)],shell=True,cwd=os.getcwd())

		if delete_cof_files:
			subprocess.call(['rm tmp.txt'],shell=True,cwd=os.getcwd())
			subprocess.call(['rm {}.eqn'.format(copfile)],shell=True,cwd=os.getcwd())
		cmd = 'python {}rename_cofac_wires.py {}.blif'.format(src_path,copfile) + ' p{}'.format(cfidx)
		subprocess.call([cmd],shell=True,cwd=os.getcwd())

		if delete_cof_files:
			subprocess.call(['rm {}.blif'.format(copfile)],shell=True,cwd=os.getcwd())

		copfile = 'cfp_{}_{}_{}_{}'.format(bnch_mark,bw,fw,cfidx)
		cfh = open('{}.blif'.format(copfile),'r')
		line = cfh.readline().strip()
		while(line[0:6] != '.names'):
			line = cfh.readline().strip()
		
		if gfc_computation:
			gfch.write(line+'\n')
		if dfc_computation:
			dfch.write(line+'\n')
			edcfh.write(line+'\n')

		for line in cfh.readlines():
			if '.end' not in line.strip():
				if gfc_computation:
					gfch.write(line)
				if dfc_computation:
					dfch.write(line)
					edcfh.write(line)
		cfh.close()
		if delete_cof_files:
			subprocess.call(['rm {}.blif'.format(copfile)],shell=True,cwd=os.getcwd())	

	tm_set = time.time()-tm0
	tm0 = time.time()
	print("Done!\n")

	if gfc_computation:

		for cofac in range(tot_sets):
			nstr = '.names cf{} '.format(cofac)
			vstr = '1'
			if cofac == 0:
				tgtstr = '{}gf{}\n{} 1\n'.format(nstr,cofac,vstr)
			else:
				for cmplfc in range(cofac-1,-1,-1):
					nstr = '{}cf{} '.format(nstr,cmplfc)
					vstr = '{}0'.format(vstr)
				tgtstr = '{}gf{}\n{} 1\n'.format(nstr,cofac,vstr)
			gfch.write(tgtstr)

		for target in range(fw):
			nstr = '.names '
			vstr = ''
			for gfidx in range(tot_sets):
				keystr = bin(gfidx)[2:].zfill(fw)
				if keystr[target] == svstr:
					nstr = '{}gf{} '.format(nstr,gfidx)
					vstr = '{}0'.format(vstr)
			if comp_using_offset:
				tgtstr = '{}{}c\n{} 0\n'.format(nstr,trgts[target],vstr)
				nstr = '.names {0}c {0}\n0 1\n'.format(trgts[target])
				tgtstr = '{}{}'.format(tgtstr,nstr)
			else:
				tgtstr = '{}{}\n{} 0\n'.format(nstr,trgts[target],vstr)
			gfch.write(tgtstr)
		gfch.write('\n.end\n')
		gfch.close()

		# Strashing & fraiging the gfc file for all targets using abc
		abcs = open('gfc_abc.script','w')
		abcs.write('source {}abc.rc\n'.format(src_path))
		abcs.write('read_library {}cadence_abc.genlib\n'.format(src_path))
		abcs.write('read_blif {}.blif\n'.format(gfcfile))
		abcs.write('strash;\n')
		abcs.write('fraig;\n')
		abcs.write(gfc_synth_str)
		if not sis_synth:
			abcs.write('map;\n')
		abcs.write('write_blif {}_abc_mapped.blif;quit;\n'.format(gfcfile))
		abcs.close()
		tm_setg = time.time()-tm0
		tm0 = time.time()
		print("Synthesizing GFC patch using abc\n")
		subprocess.call(['{}./abc -f gfc_abc.script > /dev/null'.format(src_path)],shell=True,cwd=os.getcwd())
		tm_gfcs = time.time()-tm0
		print("Done!\n")

		if sis_synth:
			print("Synthesizing GFC patch using sis\n")
			sis_s = open('sis_synth.script','w')
			sis_s.write('read_blif {}.blif\n'.format(gfcfile))
			sis_s.write('print_stats\n')
			sis_s.write(sis_synth_str)
			sis_s.write('print_stats\n')
			sis_s.write('write_blif {}_sis_mapped.blif\n'.format(gfcfile))
			sis_s.write('quit')
			sis_s.close()

			subprocess.call(['{}./sis < sis_synth.script > /dev/null'.format(src_path)],shell=True,cwd=os.getcwd())
			print("Done!\n")
			if delete_tmp_files:
				subprocess.call(['rm sis_synth.script'],shell=True,cwd=os.getcwd())
		if delete_tmp_files:
			subprocess.call(['rm gfc_abc.script'],shell=True,cwd=os.getcwd())
			subprocess.call(['rm {}.blif'.format(gfcfile)],shell=True,cwd=os.getcwd())

	tm0 = time.time()
	if dfc_computation:

		inter_dict = {}
		dcnstr = '.names '
		dcvstr = ''
		pcdc = []
		first_time = True
		for idx1 in range(tot_sets):
			enstr = '.names cf{} dcSet '.format(idx1)
			evstr = '10'
			if idx1 == 0:
				etgtstr = '{}ef{}\n{} 1\n'.format(enstr,idx1,evstr)
			else:
				for ecmplfc in range(idx1-1,-1,-1):
					enstr = '{}cf{} '.format(enstr,ecmplfc)
					evstr = '{}0'.format(evstr)
				etgtstr = '{}ef{}\n{} 1\n'.format(enstr,idx1,evstr)
			dfch.write(etgtstr)
			for idx2 in range(idx1,tot_sets):
				xbin = bin(idx1^idx2)[2:].zfill(fw)
				if (xbin.count('1') == 1):
					didx = xbin.index('1')
					idx1str = bin(idx1)[2:].zfill(fw)
					xbin = idx1str[:didx] + 'd' + idx1str[didx+1:] #0d/d0/d1/1d

					inter_dict[xbin] = '.names cf{} cf{} dc{}\n11 1\n'.format(idx1,idx2,xbin)
					dfch.write(inter_dict[xbin])
					edcfh.write(inter_dict[xbin])
					dcnstr = '{}dc{} '.format(dcnstr,xbin)
					dcvstr = '{}0'.format(dcvstr)
					if not first_time:
						edcnstr = '.names dc{} '.format(xbin)
						edcvstr = '1'
						for pdc in pcdc:
							edcnstr = '{}dc{} '.format(edcnstr,pdc)
							edcvstr = '{}0'.format(edcvstr)
						tgtstr = '{}edc{}\n{} 1\n'.format(edcnstr,xbin,edcvstr)
					else:
						tgtstr = '.names cf{} cf{} edc{}\n11 1\n'.format(idx1,idx2,xbin)
						first_time = False
					pcdc.append(xbin)
					dfch.write(tgtstr)
					edcfh.write(tgtstr)

		dfch.write('{}dcSet\n{} 0\n'.format(dcnstr,dcvstr))

		for target in range(fw):
			nstr = '.names '
			dcnstr = '.names '
			vstr = ''
			dcvstr = ''
			for dfidx in range(tot_sets):
				keystr = bin(dfidx)[2:].zfill(fw)
				if keystr[target] == svstr:
					nstr = '{}ef{} '.format(nstr,dfidx)
					vstr = '{}0'.format(vstr)
			for pdc in pcdc:
				if pdc[target] == svstr:
					nstr = '{}edc{} '.format(nstr,pdc)
					vstr = '{}0'.format(vstr)
				if pdc[target] == 'd':
					dcnstr = '{}edc{} '.format(dcnstr,pdc)
					dcvstr = '{}0'.format(dcvstr)
			if comp_using_offset:
				tgtstr = '{}{}c\n{} 0\n'.format(nstr,trgts[target],vstr)
				nstr = '.names {0}c {0}\n0 1\n'.format(trgts[target])
				tgtstr = '{}{}'.format(tgtstr,nstr)
			else:
				tgtstr = '{}{}\n{} 0\n'.format(nstr,trgts[target],vstr)
			dctgtstr = '{}{}\n{} 0\n'.format(dcnstr,trgts[target],dcvstr)
			dfch.write(tgtstr)
			edcfh.write(dctgtstr)

		edcfh.write('\n.end\n')
		dfch.close()
		edcfh.close()

		if sis_synth_dfc:
			filenames = ['{}.blif'.format(dfcfile), '{}.blif'.format(dcfile)]
			with open('{}_preSIS.blif'.format(dfcfile), 'w') as outfile:
				for fname in filenames:
					with open(fname) as infile:
						for line in infile:
							outfile.write(line)
		else:
			subprocess.call(['mv {0}.blif {0}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd(),stdout=None)


		if delete_tmp_files:
			if sis_synth_dfc:
				subprocess.call(['rm {}.blif'.format(dfcfile)],shell=True,cwd=os.getcwd())
			subprocess.call(['rm {}.blif'.format(dcfile)],shell=True,cwd=os.getcwd())
		
		if sis_synth_dfc: 
			print("Synthesizing DFC patch using sis\n")
			sis = open('sis_ondc.script','w')
			sis.write('read_blif {}_preSIS.blif\n'.format(dfcfile))
			sis.write('print_stats\n')
			sis.write(sis_synth_str)
			sis.write('print_stats\n')
			sis.write('write_blif {}_postSIS.blif\n'.format(dfcfile))
			sis.write('quit')
			sis.close()
			tm_setd = time.time()-tm0
			tm0 = time.time()

			subprocess.call(['{}./sis < sis_ondc.script > /dev/null'.format(src_path)],shell=True,cwd=os.getcwd(),stdout=None)
			print("Done!\n")
			try:
				log = open('{0}_postSIS.blif'.format(dfcfile),'r')
			except IOError:
				subprocess.call(['cp {0}_preSIS.blif {0}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd(),stdout=None)
			if delete_tmp_files:
				subprocess.call(['rm sis_ondc.script'],shell=True,cwd=os.getcwd())
				subprocess.call(['rm {}_preSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd())
		# else:
			# subprocess.call(['mv {0}_preSIS.blif {0}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd(),stdout=None)			
		
		tm_sdfcs = time.time()-tm0
		tm0 = time.time()

		tmp = open('dfc_abc_synth.script','w')
		tmp.write('source {}abc.rc\n'.format(src_path))
		tmp.write('read_blif {}_postSIS.blif\n'.format(dfcfile))
		if sis_synth_dfc:
			tmp.write('exdc_free\n')
		tmp.write('strash;\n')
		tmp.write('fraig;\n')
		tmp.write('read_library {}cadence_abc.genlib;\n'.format(src_path))
		tmp.write(dfc_synth_str)
		tmp.write('map;\n')
		tmp.write('write_blif {}_abc_mapped.blif;quit;\n'.format(dfcfile))
		tmp.close()

		print("Synthesizing DFC patch using abc\n")
		subprocess.call(['{}./abc -f dfc_abc_synth.script > /dev/null'.format(src_path)],shell=True,cwd=os.getcwd(),stdout=subprocess.PIPE)
		print("Done!\n")

		if delete_tmp_files:
			subprocess.call(['rm dfc_abc_synth.script'],shell=True,cwd=os.getcwd())
			subprocess.call(['rm {}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd())

		tm_adfcs = time.time()-tm0

	tmp = open('gfc_dfc_abc_stats.script','w')
	tmp.write('read_library {}cadence_abc.genlib;\n'.format(src_path))
	tmp.write('source {}abc.rc;\n'.format(src_path))
	if gfc_computation:
		tmp.write('read_blif {}_abc_mapped.blif\n'.format(gfcfile))
		tmp.write('ps;\n')
	if dfc_computation:
		tmp.write('read_blif {}_abc_mapped.blif\n'.format(dfcfile))
		tmp.write('ps;\n')
	tmp.write('quit;\n')
	tmp.close()
	print_time(tm_abc_aig,tm_set,tm_setg,tm_setd,tm_gfcs,tm_sdfcs,tm_adfcs)

# capture the model info and comments
cline = read_a_line(blifFile)
bnch_mark = ''

while(cline[0:6] != '.model'):
	cline = cline.split()
	bnch_mark = cline[1]
	cline = read_a_line(blifFile)

while(cline[0:7] != '.inputs'):
	logFile.write(cline+'\n')
	cline = read_a_line(blifFile)

while(cline[0:8] != '.outputs'):
	inps += cline.strip().split()
	# cline = blifFile.readline().strip()
	cline = read_a_line(blifFile)

while(cline[0:5] != '.gate'):
	outps += cline.strip().split()
	# cline = blifFile.readline().strip()
	cline = read_a_line(blifFile)

#Removing the string inputs and outputs from the list
inps.pop(0)
outps.pop(0)

# pdb.set_trace()
inpStr = inps[0]
outStr = outps[0]
logFile.write(check_bnchmrk_format(inpStr)+'\n')
inp_frmt = set_input_format(inpStr)

inpLen = len(inps)
bitWidth = inpLen/2

#Confirm if number of outputs = inputs (2*n = n+n)
assert(len(outps) == inpLen)

logFile.write("Working on {}-bit multiplier.".format(bitWidth)+'\n')

tm0 = time.time()
tm_bugp = time.time()-tm0
if random_bug:
	logFile.write("Adding {} bugs at random locations with bug config {}".format(num_trgts,bug_config)+'\n')
	cmd = 'python {}utilities.py {} {} {} {} {}'.format(src_path, baseFile, bitWidth, num_trgts, bug_config, inpStr)
	logFile.write(cmd+'\n')
	subprocess.call([cmd],shell=True,cwd=os.getcwd())
else:
	logFile.write("Adding {} bugs at pre-determined locations with bug config {}".format(num_trgts,bug_config)+'\n')

tm_bugp = time.time()-tm0

#patch file generated after adding bugs
pName = '{}_p{}_pready'.format(bfName,num_trgts)
pFile = pName + '.blif'

with open(pFile,'r') as pFH:
	line0 = pFH.readline()	

jtrgts = line0.lstrip().split('#')
if random_bug:
	bugstr = jtrgts[1].strip().split()
	assert(len(bugstr) == num_trgts)
	logFile.write("Bugs added at locations {}".format(' '.join(bugstr))+'\n')
else:
	bugstr = jtrgts[1].strip()
	logFile.write("Bugs added at locations {}".format(bugstr)+'\n')

logFile.write("Rectifying at targets - ")
targetstr = ''
if random_bug:
	for target in range(num_trgts):
		#Always rectify at rg*2
		# rectLoc = 2
		if target%2 == 0: #rectify at rg*3
			rectLoc = 3
		else: # rectify at rg*4
			rectLoc = 4
		targetstr += '{}{}{} '.format(rs,target,rectLoc)
else:
	targetstr = bugstr
logFile.write(targetstr+'\n')
logFile.write("Generating AIG's and remainders for each assignments to targets\n")
blifFile.close()

#Goto end of file
if use_tool == 'revsca':
	remlog = open(remFile,'w')
	remlog.write("Targets: {}\n".format(targetstr))
	remlog.close()
else:
	subprocess.call(['rm -rf {}'.format(remFile)],stdout=logFile,shell=True,cwd=os.getcwd())
	remlog = open(remFile,'a')
	remlog.write("Targets: {}\n".format(targetstr))
	remlog.flush()
first_time = True
trgts = targetstr.split()
assert(len(trgts) == num_trgts)

# if use_tool == 'revsca':
# 	remlog = open(remFile,'a')
subprocess.call(['rm -rf rev_sca.out'],stdout=logFile,shell=True,cwd=os.getcwd())
logFile.flush()

tm0 = time.time()
tm_remgen = time.time()-tm0
write_abc_aig_cofac_gen_script()

for cofacs in range(2**num_trgts):
	keystr = bin(cofacs)[2:].zfill(num_trgts)
	pFH = open(pFile,'r+')
	pFH.seek(0, os.SEEK_END)
	pos = pFH.tell() - 1
	if not first_time:
		strip_last_x_lines(num_trgts)
	pFH.write('\n\n')
	for target in range(num_trgts):
		#Always rectify at rg*2
		# rectLoc = 2
		if random_bug:
			if target%2 == 0: #rectify at rg*3
				rectLoc = 3
			else: # rectify at rg*4
				rectLoc = 4
			if keystr[target] == '0':
				pFH.write('.gate ZERO Y={}{}{}\n'.format(rs,target,rectLoc))
			if keystr[target] == '1':
				pFH.write('.gate ONE Y={}{}{}\n'.format(rs,target,rectLoc))      	
		else:
			if keystr[target] == '0':
				pFH.write('.gate ZERO Y={}\n'.format(trgts[target]))
			if keystr[target] == '1':
				pFH.write('.gate ONE Y={}\n'.format(trgts[target]))
	pFH.write('.end\n')
	first_time = False
	pFH.close()
	logFile.write('Generating cofactor remainder {}\n'.format(cofacs))
	print('Generating cofactor remainder {}\n'.format(cofacs))

	subprocess.call(['{}abc -f abc_gen_aig_cofacs.script '.format(src_path)],stdout=logFile,shell=True,cwd=os.getcwd())
	if use_amulet20:
		subprocess.call(['{}ramulet -rectify {}.aig {} '.format(src_path,pName,remFile)],stdout=logFile,shell=True,cwd=os.getcwd())
	elif use_amulet15:
		subprocess.call(['{}ramulet15 -rectify {}.aig {}'.format(src_path,pName,remFile)],stdout=logFile,shell=True,cwd=os.getcwd())
	# elif use_amulet10:
	# 	subprocess.call(['../amulet1.0/amulet -verify {}.aig {}'.format(pName,remFile)],stdout=logFile,shell=True,cwd=os.getcwd())
	elif use_revsca: #-u for unsigned multiplier -s for signed
		subprocess.call(['{}revsca20 {}.aig dummy.txt -u >> rev_sca.out'.format(src_path,pName)],stdout=logFile,shell=True,cwd=os.getcwd())
	else:	
		subprocess.call(['../amulet1.5/amulet -verify {}.aig {}'.format(pName,remFile)],stdout=logFile,shell=True,cwd=os.getcwd())

	logFile.write('cofactor remainder {} generated\n'.format(cofacs))
	print('cofactor remainder {} generated\n'.format(cofacs))

if delete_cof_files:
	subprocess.call(['rm {}.aig'.format(pName)],shell=True,cwd=os.getcwd())
	subprocess.call(['rm -rf dummy.txt'],stdout=logFile,shell=True,cwd=os.getcwd())

#Be careful and make sure to check if it is deleting more lines than what it's supposed to
# if the lines aren't deleted - could cause segmentation fault whilst running abc or revsca
with open(pFile,'r+') as pFH:
	strip_last_x_lines(num_trgts-1)

subprocess.call(['rm abc_gen_aig_cofacs.script'],shell=True,cwd=os.getcwd())

logFile.write("Remainder generation done !!\n")
tm_remgen = time.time()-tm0

tm0 = time.time()
tm_setup_poly = time.time()-tm0
if use_tool == 'revsca':
	process_revsca_output()
else:
	remlog.close()


subprocess.call(['rm -rf rev_sca.out'],stdout=logFile,shell=True,cwd=os.getcwd())
tm_singular_comp = time.time()-tm0
tm_func_comp = time.time()-tm0
if (use_singular and use_singular_for_poly_mult):
	write_poly_script_for_singular()
	tm_setup_poly = time.time()-tm0

	tm0 = time.time()
	compute_rc_and_boolrem_using_singular()
	tm_singular_comp = time.time()-tm0

	# rect_exists = check_if_rect_exists()
	# print(rect_exists)
	# if rect_exists:
	tm0 = time.time()
	compute_functions()
	tm_func_comp = time.time()-tm0
# else:
# 	write_poly_mul_script_for_amulet()
# 	run_rect_check_using_polylib()
tm_total = time.time() - tm_st

print_overall_time(tm_bugp,tm_remgen,tm_setup_poly,tm_singular_comp,tm_func_comp)

subprocess.call(['{}abc -f gfc_dfc_abc_stats.script'.format(src_path)],stdout=logFile,shell=True,cwd=os.getcwd())

logFile.write("Total time: {}".format(round(tm_total,1)))
logFile.close()
