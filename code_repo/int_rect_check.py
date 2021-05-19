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
# import re
import os
import subprocess
import time
import pdb

# from utilities import *

abc_synth = False

delete_cof_files = True
delete_tmp_files = False
src_path = '../code_repo/'

###################################################################
##################### Time stamp for procedures ###################
###################################################################
def print_time(tm_abc_aig='N/A',
			   tm_set='N/A',
			   tm_setg='N/A',
			   tm_setd='N/A',
			   tm_gfcs='N/A',
			   tm_sdfcs='N/A',
			   tm_adfcs='N/A'):

	print '\n------------------- Time Data -------------------'
	print 'create aigs using abc             			', round(tm_abc_aig,1)
	print 'Total setup time for gfc files (cofacs)[2:].zfill(num_trgts)

	if not first_time:
		pFH.seek(0, os.SEEK_END)
		pos = pFH.tell() - 1

		for _ in range(num_trgts+1):
			while pos > 0 and pFH.read(1) != "\n":
				pos -= 1
				pFH.seek(pos, os.SEEK_SET)

		if pos > 0:
			pFH.seek(pos, os.SEE				', round(tm_set+tm_setg,1)
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
tm0 = time.time()

curr_wd = os.getcwd()

total_args = len(sys.argv)-1
expctd_args = 3
inps = []
outps = []
rs = 'rg'

if (total_args < expctd_args):
	print ("Expected {} input argument file(s)!!".format(expctd_args))
	sys.exit(0)
else:
	fileInput     = sys.argv[1]
	num_trgts     = int(sys.argv[2])
	bug_config    = int(sys.argv[3])
	dirName       = os.path.dirname(fileInput)
	baseFile      = os.path.basename(fileInput)
	os.chdir('{}/{}/'.format(curr_wd,dirName))
	try:
		blifFile = open(baseFile,'r')
	except IOError:
		print ("Couldn't read the input file using handler!!")
		sys.exit(0)

#Placeholder code
if bug_config == 1:#bugs/targets near PI
	pass
elif bug_config == 2: #bugs/targets near mid
	pass
elif bug_config == 3: #bugs/targets near PO
	pass
else: # default bugs near PI
	pass

#baseFileName
bfName = baseFile.strip('.blif')

#open a log file for tracking model info and bug info
logFile = '{}.log'.format(bfName)
remFile = 'rem_{}.log'.format(bfName)
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
	if line.rstrip():
		return line.strip().strip(';\\')
	else:
		return read_a_line(fhandle)

def check_bnchmrk_format(inpStr):

	return {
		'IN1[0]':"Aoki format - Input:{},Output:{}".format(inps[1],outps[1]) ,
		'a0':"abc format - Input:{},Output:{}".format(inps[1],outps[1]),
		'a[0]':"Btor format - Input:{},Output:{}".format(inps[1],outps[1]),
	}[inpStr]

# capture the model info and comments
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

inpStr = inps[0]
outStr = outps[0]
logFile.write(check_bnchmrk_format(inpStr)+'\n')

inpLen = len(inps)
bitWidth = inpLen/2

#Confirm if number of outputs = inputs (2*n = n+n)
assert(len(outps) == inpLen)

logFile.write("Working on {}-bit multiplier.".format(bitWidth)+'\n')
logFile.write("Adding {} bugs at random locations with bug config {}".format(num_trgts,bug_config)+'\n')

cmd = 'python {}utilities.py {} {} {} {} {}'.format(src_path, baseFile, bitWidth, num_trgts, bug_config, inpStr)
logFile.write(cmd+'\n')
subprocess.call([cmd],shell=True,cwd=os.getcwd())

#patch file generated after adding bugs
pFile = '{}_p{}_pready.blif'.format(bfName,num_trgts)
pdb.set_trace()
try:
	pFH = open(pFile,'wr+')
except IOError:
	print ("Couldn't open patch file for reading, check add_bug module!!")
	sys.exit(0)

line0 = pFH.readline()

jtrgts = line0.lstrip().split('#')
targetstr = jtrgts[1].strip().split()

assert(len(targetstr) == num_trgts)

logFile.write("Bugs added at locations {}".format(' '.join(targetstr))+'\n')
blifFile.close()

#Goto end of file
remlog = open(remFile,'w')
remlog.write("Targets: {}\n".format(' '.join(targetstr)))
first_time = True

for cofacs in range(2**num_trgts):
	keystr = bin(cofacs)[2:].zfill(num_trgts)

	if not first_time:
		pFH.seek(0, os.SEEK_END)
		pos = pFH.tell() - 1

		for _ in range(num_trgts+1):
			while pos > 0 and pFH.read(1) != "\n":
				pos -= 1
				pFH.seek(pos, os.SEEK_SET)

		if pos > 0:
			pFH.seek(pos, os.SEEK_SET)
			pFH.truncate()

	for target in range(num_trgts):
		if keystr[target] == '0':
			pFH.write('.gate ZERO Y={}{}2\n'.format(rs,target))
		if keystr[target] == '1':
			pFH.write('.gate ONE Y={}{}2\n'.format(rs,target))      	
	pFH.write('.end\n')
	first_time = False
	pFH.close()
	pdb.set_trace()

logFile.close()


# # Proceeding to analyze cofactor log file to compute the MFR patches.
# # Write the ON-set and OFFC-set files from .
# bnchmrk_dtls = read_a_line(log).split()

# #Verify bench mark details again
# bnch_mark = (bnchmrk_dtls.pop(0))
# bw = int(bnchmrk_dtls.pop(0))
# fw = int(bnchmrk_dtls.pop(0))
# trgts = read_a_line(log).split()

# cofacsp = []
# cofacsn = []

# for num_cofacs in range((2**fw)):
# 	cofac = read_a_line(log)
# 	if cofac != '':
# 		cofacsp.append('!('+cofac+')')
# 	else:
# 		print ("empty section")

# log.close()

# assert(len(cofacsp) == (2**fw))

# tot_sets = len(cofacsp)
# tm_set = 0.0
# tm_setg = 0.0
# tm_setd = 0.0
# tm_gfcs = 0.0
# tm_sdfcs = 0.0
# tm_adfcs = 0.0

# if gfc_computation:

# 	gfcfile    = 't{}_gfc_{}_{}_{}'.format(fstr,bnch_mark,bw,fw)
# 	gfch = open('{}.blif'.format(gfcfile),'w')
# 	gfch.write('# BLIF for all the targets computed using {}-sets of GFC computations\n'.format(fstr))
# 	gfch.write('.model {}\n.inputs '.format(gfcfile))
# 	write_inputs(gfch, bw, bnch_mark)
# 	gfch.write('\n.outputs ')

# 	for target in range(fw):
# 		gfch.write(trgts[target]+' ')

# 	gfch.write('\n')

# if dfc_computation:

# 	dfcfile = 't{}dc_dfc_{}_{}_{}'.format(fstr,bnch_mark,bw,fw)
# 	dcfile = 'tdc_dfc_{}_{}_{}'.format(bnch_mark,bw,fw)
# 	dfch = open('{}.blif'.format(dfcfile),'w')
# 	edcfh = open('{}.blif'.format(dcfile),'w')
# 	dfch.write('# BLIF for all the targets computed using {}-sets of DFC computations\n'.format(fstr))
# 	edcfh.write('\n# exdc BLIF for all the targets computed using {}-sets of DFC computations\n'.format(fstr))
# 	dfch.write('.model {}\n.inputs '.format(dfcfile))
# 	edcfh.write('.exdc \n.inputs ')
# 	write_inputs(dfch, bw, bnch_mark)
# 	write_inputs(edcfh, bw, bnch_mark)
# 	dfch.write('\n.outputs ')
# 	edcfh.write('\n.outputs ')

# 	for target in range(fw):
# 		dfch.write(trgts[target]+' ')
# 		edcfh.write(trgts[target]+' ')
# 	dfch.write('\n')
# 	edcfh.write('\n')

# '''
# Cofactor to merging

# '''
# print("\nComputing BLIFS for cofactors\n")
# for cfidx in range(len(cofacsp)):

# 	copfile = 'cofp_{}_{}_{}_{}'.format(bnch_mark,bw,fw,cfidx)
# 	cpfh = open('{}.eqn'.format(copfile),'w')
# 	cpfh.write('INORDER = ')
# 	write_inputs(cpfh, bw, bnch_mark)
# 	cpfh.write(';\nOUTORDER = cf{} ;\n'.format(cfidx))
# 	cpfh.write('cf{} = {};'.format(cfidx,cofacsp[cfidx]))
# 	cpfh.close()

# 	tmp = open('tmp.txt','w')
# 	tmp.write('source abc.rc\n'.format(src_path))
# 	tmp.write('read_eqn {}.eqn;\n'.format(copfile))
# 	tmp.write('strash;\n') 
# 	tmp.write('fraig;\n')
# 	tmp.write(cofac_synth)
# 	tmp.write('write_blif {}.blif;quit;\n'.format(copfile))

# 	tmp.close()

# 	subprocess.call(['./abc -f tmp.txt  > /dev/null'],shell=True,cwd=os.getcwd())

# 	if delete_cof_files:
# 		subprocess.call(['rm tmp.txt'],shell=True,cwd=os.getcwd())
# 		subprocess.call(['rm {}.eqn'.format(copfile)],shell=True,cwd=os.getcwd())

# 	cmd = 'python {}rename_cofac_wires.py {}.blif'.format(src_path,copfile) + ' p{}'.format(cfidx)
# 	subprocess.call([cmd],shell=True,cwd=os.getcwd())

# 	if delete_cof_files:
# 		subprocess.call(['rm {}.blif'.format(copfile)],shell=True,cwd=os.getcwd())

# 	copfile = 'cfp_{}_{}_{}_{}'.format(bnch_mark,bw,fw,cfidx)
# 	cfh = open('{}.blif'.format(copfile),'r')
# 	line = cfh.readline().strip()
# 	while(line[0:6] != '.names'):
# 		line = cfh.readline().strip()
	
# 	if gfc_computation:
# 		gfch.write(line+'\n')
# 	if dfc_computation:
# 		dfch.write(line+'\n')
# 		edcfh.write(line+'\n')

# 	for line in cfh.readlines():
# 		if '.end' not in line.strip():
# 			if gfc_computation:
# 				gfch.write(line)
# 			if dfc_computation:
# 				dfch.write(line)
# 				edcfh.write(line)
# 	cfh.close()
# 	if delete_cof_files:
# 		subprocess.call(['rm {}.blif'.format(copfile)],shell=True,cwd=os.getcwd())	

# tm_set = time.time()-tm0
# tm0 = time.time()
# print("Done!\n")

# if gfc_computation:

# 	for cofac in range(tot_sets):
# 		nstr = '.names cf{} '.format(cofac)
# 		vstr = '1'
# 		if cofac == 0:
# 			tgtstr = '{}gf{}\n{} 1\n'.format(nstr,cofac,vstr)
# 		else:
# 			for cmplfc in range(cofac-1,-1,-1):
# 				nstr = '{}cf{} '.format(nstr,cmplfc)
# 				vstr = '{}0'.format(vstr)
# 			tgtstr = '{}gf{}\n{} 1\n'.format(nstr,cofac,vstr)
# 		gfch.write(tgtstr)

# 	for target in range(fw):
# 		nstr = '.names '
# 		vstr = ''
# 		for gfidx in range(tot_sets):
# 			keystr = bin(gfidx)[2:].zfill(fw)
# 			if keystr[target] == svstr:
# 				nstr = '{}gf{} '.format(nstr,gfidx)
# 				vstr = '{}0'.format(vstr)
# 		if comp_using_offset:
# 			tgtstr = '{}{}c\n{} 0\n'.format(nstr,trgts[target],vstr)
# 			nstr = '.names {0}c {0}\n0 1\n'.format(trgts[target])
# 			tgtstr = '{}{}'.format(tgtstr,nstr)
# 		else:
# 			tgtstr = '{}{}\n{} 0\n'.format(nstr,trgts[target],vstr)
# 		gfch.write(tgtstr)
# 	gfch.write('\n.end\n')
# 	gfch.close()

# 	# Strashing & fraiging the gfc file for all targets using abc
# 	abcs = open('gfc_abc.script','w')
# 	abcs.write('source abc.rc\n')
# 	abcs.write('read_library cadence_abc.genlib\n')
# 	abcs.write('read_blif {}.blif\n'.format(gfcfile))
# 	abcs.write('strash;\n')
# 	abcs.write('fraig;\n')
# 	abcs.write(gfc_synth_str)
# 	if not sis_synth:
# 		abcs.write('map;\n')
# 	abcs.write('write_blif {}_abc_mapped.blif;quit;\n'.format(gfcfile))
# 	abcs.close()
# 	tm_setg = time.time()-tm0
# 	tm0 = time.time()
# 	print("Synthesizing GFC patch using abc\n")
# 	subprocess.call(['./abc -f gfc_abc.script > /dev/null'],shell=True,cwd=os.getcwd())
# 	tm_gfcs = time.time()-tm0
# 	print("Done!\n")

# 	if sis_synth:
# 		print("Synthesizing GFC patch using sis\n")
# 		sis_s = open('sis_synth.script','w')
# 		sis_s.write('read_blif {}.blif\n'.format(gfcfile))
# 		sis_s.write('print_stats\n')
# 		sis_s.write(sis_synth_str)
# 		sis_s.write('print_stats\n')
# 		sis_s.write('write_blif {}_sis_mapped.blif\n'.format(gfcfile))
# 		sis_s.write('quit')
# 		sis_s.close()

# 		subprocess.call(['./sis < sis_synth.script > /dev/null'],shell=True,cwd=os.getcwd())
# 		print("Done!\n")
# 		if delete_tmp_files:
# 			subprocess.call(['rm sis_synth.script'],shell=True,cwd=os.getcwd())
# 	if delete_tmp_files:
# 		subprocess.call(['rm gfc_abc.script'],shell=True,cwd=os.getcwd())
# 		subprocess.call(['rm {}.blif'.format(gfcfile)],shell=True,cwd=os.getcwd())

# tm0 = time.time()
# if dfc_computation:

# 	inter_dict = {}
# 	dcnstr = '.names '
# 	dcvstr = ''
# 	pcdc = []
# 	first_time = True
# 	for idx1 in range(tot_sets):
# 		enstr = '.names cf{} dcSet '.format(idx1)
# 		evstr = '10'
# 		if idx1 == 0:
# 			etgtstr = '{}ef{}\n{} 1\n'.format(enstr,idx1,evstr)
# 		else:
# 			for ecmplfc in range(idx1-1,-1,-1):
# 				enstr = '{}cf{} '.format(enstr,ecmplfc)
# 				evstr = '{}0'.format(evstr)
# 			etgtstr = '{}ef{}\n{} 1\n'.format(enstr,idx1,evstr)
# 		dfch.write(etgtstr)
# 		for idx2 in range(idx1,tot_sets):
# 			xbin = bin(idx1^idx2)[2:].zfill(fw)
# 			if (xbin.count('1') == 1):
# 				didx = xbin.index('1')
# 				idx1str = bin(idx1)[2:].zfill(fw)
# 				xbin = idx1str[:didx] + 'd' + idx1str[didx+1:] #0d/d0/d1/1d

# 				inter_dict[xbin] = '.names cf{} cf{} dc{}\n11 1\n'.format(idx1,idx2,xbin)
# 				dfch.write(inter_dict[xbin])
# 				edcfh.write(inter_dict[xbin])
# 				dcnstr = '{}dc{} '.format(dcnstr,xbin)
# 				dcvstr = '{}0'.format(dcvstr)
# 				if not first_time:
# 					edcnstr = '.names dc{} '.format(xbin)
# 					edcvstr = '1'
# 					for pdc in pcdc:
# 						edcnstr = '{}dc{} '.format(edcnstr,pdc)
# 						edcvstr = '{}0'.format(edcvstr)
# 					tgtstr = '{}edc{}\n{} 1\n'.format(edcnstr,xbin,edcvstr)
# 				else:
# 					tgtstr = '.names cf{} cf{} edc{}\n11 1\n'.format(idx1,idx2,xbin)
# 					first_time = False
# 				pcdc.append(xbin)
# 				dfch.write(tgtstr)
# 				edcfh.write(tgtstr)

# 	dfch.write('{}dcSet\n{} 0\n'.format(dcnstr,dcvstr))

# 	for target in range(fw):
# 		nstr = '.names '
# 		dcnstr = '.names '
# 		vstr = ''
# 		dcvstr = ''
# 		for dfidx in range(tot_sets):
# 			keystr = bin(dfidx)[2:].zfill(fw)
# 			if keystr[target] == svstr:
# 				nstr = '{}ef{} '.format(nstr,dfidx)
# 				vstr = '{}0'.format(vstr)
# 		for pdc in pcdc:
# 			if pdc[target] == svstr:
# 				nstr = '{}edc{} '.format(nstr,pdc)
# 				vstr = '{}0'.format(vstr)
# 			if pdc[target] == 'd':
# 				dcnstr = '{}edc{} '.format(dcnstr,pdc)
# 				dcvstr = '{}0'.format(dcvstr)
# 		if comp_using_offset:
# 			tgtstr = '{}{}c\n{} 0\n'.format(nstr,trgts[target],vstr)
# 			nstr = '.names {0}c {0}\n0 1\n'.format(trgts[target])
# 			tgtstr = '{}{}'.format(tgtstr,nstr)
# 		else:
# 			tgtstr = '{}{}\n{} 0\n'.format(nstr,trgts[target],vstr)
# 		dctgtstr = '{}{}\n{} 0\n'.format(dcnstr,trgts[target],dcvstr)
# 		dfch.write(tgtstr)
# 		edcfh.write(dctgtstr)

# 	edcfh.write('\n.end\n')
# 	dfch.close()
# 	edcfh.close()

# 	if sis_synth_dfc:
# 		filenames = ['{}.blif'.format(dfcfile), '{}.blif'.format(dcfile)]
# 		with open('{}_preSIS.blif'.format(dfcfile), 'w') as outfile:
# 			for fname in filenames:
# 				with open(fname) as infile:
# 					for line in infile:
# 						outfile.write(line)
# 	else:
# 		subprocess.call(['mv {0}.blif {0}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd(),stdout=None)


# 	if delete_tmp_files:
# 		if sis_synth_dfc:
# 			subprocess.call(['rm {}.blif'.format(dfcfile)],shell=True,cwd=os.getcwd())
# 		subprocess.call(['rm {}.blif'.format(dcfile)],shell=True,cwd=os.getcwd())
	
# 	if sis_synth_dfc: 
# 		print("Synthesizing DFC patch using sis\n")
# 		sis = open('sis_ondc.script','w')
# 		sis.write('read_blif {}_preSIS.blif\n'.format(dfcfile))
# 		sis.write('print_stats\n')
# 		sis.write(sis_synth_str)
# 		sis.write('print_stats\n')
# 		sis.write('write_blif {}_postSIS.blif\n'.format(dfcfile))
# 		sis.write('quit')
# 		sis.close()
# 		tm_setd = time.time()-tm0
# 		tm0 = time.time()

# 		subprocess.call(['./sis < sis_ondc.script > /dev/null'],shell=True,cwd=os.getcwd(),stdout=None)
# 		print("Done!\n")
# 		try:
# 			log = open('{0}_postSIS.blif'.format(dfcfile),'r')
# 		except IOError:
# 			subprocess.call(['cp {0}_preSIS.blif {0}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd(),stdout=None)
# 		if delete_tmp_files:
# 			subprocess.call(['rm sis_ondc.script'],shell=True,cwd=os.getcwd())
# 			subprocess.call(['rm {}_preSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd())
# 	# else:
# 		# subprocess.call(['mv {0}_preSIS.blif {0}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd(),stdout=None)			
	
# 	tm_sdfcs = time.time()-tm0
# 	tm0 = time.time()

# 	tmp = open('dfc_abc_synth.script','w')
# 	tmp.write('source abc.rc\n')
# 	tmp.write('read_blif {}_postSIS.blif\n'.format(dfcfile))
# 	if sis_synth_dfc:
# 		tmp.write('exdc_free\n')
# 	tmp.write('strash;\n')
# 	tmp.write('fraig;\n')
# 	tmp.write('read_library cadence_abc.genlib;\n')
# 	tmp.write(dfc_synth_str)
# 	tmp.write('map;\n')
# 	tmp.write('write_blif {}_abc_mapped.blif;quit;\n'.format(dfcfile))
# 	tmp.close()

# 	print("Synthesizing DFC patch using abc\n")
# 	subprocess.call(['./abc -f dfc_abc_synth.script > /dev/null'],shell=True,cwd=os.getcwd(),stdout=subprocess.PIPE)
# 	print("Done!\n")

# 	if delete_tmp_files:
# 		subprocess.call(['rm dfc_abc_synth.script'],shell=True,cwd=os.getcwd())
# 		subprocess.call(['rm {}_postSIS.blif'.format(dfcfile)],shell=True,cwd=os.getcwd())

# 	tm_adfcs = time.time()-tm0

# tmp = open('gfc_dfc_abc_stats.script','w')
# tmp.write('read_library cadence_abc.genlib;\n')
# if gfc_computation:
# 	tmp.write('read_blif {}/{}_abc_mapped.blif\n'.format(dirName,gfcfile))
# 	tmp.write('ps;\n')
# if dfc_computation:
# 	tmp.write('read_blif {}/{}_abc_mapped.blif\n'.format(dirName,dfcfile))
# 	tmp.write('ps;\n')
# tmp.write('quit;\n')
# tmp.close()

# print_time(tm_set,tm_setg,tm_setd,tm_gfcs,tm_sdfcs,tm_adfcs)