import os
import re
import subprocess
import pdb

# def split_revsca_polynomial(polynomial):

# 	polyList = polynomial.split('+')

# 	termsr = [['0' for x in range(2)] for y in range(len(polyList))]

# 	for idx in range(len(polyList)):
# 		# print("for poly: {}".format(polyList[idx]))
# 		coeff = polyList[idx].strip().split('\xc3\x97',1)
# 		# print("coeff:{}".format(coeff))
# 		termsr[idx][0] = coeff[0].strip()
# 		if (len(coeff) == 2):
# 			termsr[idx][1] = coeff[1].strip()

# 		del coeff

# 	return termsr 

# def write_poly_mul_script_for_amulet(bitWidth,num_trgts,remFile,rcFile,logFile):
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
	pm.write("\tMonomial * {} = new Monomial(coeff,0);\n\n".format(m_str))
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
		# if (use_tool == 'revsca'):
		# 	terms = split_revsca_polynomial(polynomial)
		# 	termRange = len(terms)
		# else:
		terms = re.findall(r'([-+]?\d*)([ab\d*\*]*)',polynomial)

		print(len(terms))
		termRange = len(terms)-1
		p_str = "p_{}".format(cofac)
		for idx in range(termRange): # Last term is dummy due to null character
			# pdb.set_trace()
			# terms[idx][0] = coefficient 
			# terms[idx][1] = corresponding monomial
			# cofac - index for remainder (00 - rem_00, 01- rem_01, 10 - rem_10 ... so on)
			# idx  - index for each term in the polynomial of a given remainder
			if terms[idx][0] == '+4112':
				print("yello")
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

def run_rect_check_using_polylib():

	#Merge all three files using shell and then delete them
	cmd = 'cp {0} {1}demo_polylib.cpp;cd {1};make clean; sh ./configure.sh; make;./demo;cd ..;'.format(rcFile,rcheck_dir)
	subprocess.call([cmd],stdout=logFile,shell=True,cwd=os.getcwd())
	logFile.write("*** Rectification check done *** \n")

def write_poly_mul_script_for_amulet_2():

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
	# p_map = defaultdict(list)
	
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
			logFile.write("Constant assignment {} to the targets rectifies the circuit".format(bin(idx)[2:].zfill(num_trgts)))
			# cleanup()
			sys.exit(0)

		polynomial = line.strip()
		terms = re.findall(r'([-+]?\d*)([ab\d*\*]*)',polynomial)

		p_str = "p_{}".format(cofac)
		
		for idx in range(len(terms)-1): # Last term is dummy due to null character
			# terms[idx][0] = coefficient 
			# terms[idx][1] = corresponding monomial
			# cofac - index for remainder (00 - rem_00, 01- rem_01, 10 - rem_10 ... so on)
			# idx  - index for each term in the polynomial of a given remainder
			# pdb.set_trace()
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
					if terms[idx][1]:
						t_vars = terms[idx][1].lstrip("*").split("*")
						for varbl in t_vars:
							pm.write("\tadd_to_vstack({});\n".format(varbl))
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

				t_map.add(thash)
				m_map.add(mhash)

				dl.write("\tdelete({});\n".format(m_str))
			pl.write("\tpush_mstack({}->copy());\n".format(m_str))
			# p_map[cofac+1].append(mhash)

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


bitWidth = 8
num_trgts = 2
remFile = 'rem.log'
rcFile = 'test.cpp'
log = 'temp.log'
use_tool = 'amulet15'
rcheck_dir = 'rect_check/'

logFile = open("{}".format(log),'w')
write_poly_mul_script_for_amulet()
run_rect_check_using_polylib()
logFile.close()