############################################################################################################
# Author : Vikas
# Intent   - To add Don't care logic with a bug at specified 
#		  	nets in the input alg and blif files.
#		   - It is necessary to have both the formats (*.alg/*.blif) since, we want to retain the
#			 information of the nets where the bugs are introduced.
#			 This is done to avoid the discrepancies caused by abc after reading the circuit.
#			 *.alg is used in PolyBori framework and *.blif is used in abc for patch verification.
# Usage    - *.py <input_file.alg> <input_file.blif> <number of bugs> <string name for redundant variables> 
#									<bug_net bug_net_fanin_1 bug_net_fanin_2> ...
#		   - Example: *.py MAS_16.sing MAS_16.blif 1 rg n36 n35 n32
#		    	- Introduce the redundant logic with a bug at gate output 
#					n36 with fanins n35 and n32 with pre-pended variable name 'rg'	
# Notation - rg - redundant_gate
#          - gb - gate bug
# Outputs  - Dump a *.sing file with bugs added at the specified nets
#		   - Dump a *.blif file with bugs added at the specified gates
#          - Dump a *_patch_ready.blif file with bugs added and targets commented
##############################################################################################################

import sys
import subprocess
import time
import os
import re
import random


usage = ''' Author - Vikas Rao
			Intent   - To add Don't care logic with a bug at specified nets in the input alg and blif files.
  		   - It is necessary to have both the formats (*.alg/*.blif) since, we want to retain the
  			 information of the nets where the bugs are introduced.
  			 This is done to avoid the discrepancies caused by abc after reading the circuit.
  			 *.alg is used in PolyBori framework and *.blif is used in abc for patch verification.
  Usage    - *.py <input_file.alg> <input_file.blif> <number of bugs> <string name for redundant variables> 
  									<bug_net bug_net_fanin_1 bug_net_fanin_2> ...
  		   - Example: *.py MAS_16.sing MAS_16.blif 1 rg n36 n35 n32
  		    	- Introduce the redundant logic with a bug at gate output 
  					n36 with fanins n35 and n32 with pre-pended variable name 'rg'	
  Notation - rg - redundant_gate
           - gb - gate bug
  Outputs  - Dump a *.sing file with bugs added at the specified nets
  		   - Dump a *.blif file with bugs added at the specified gates
           - Dump a *_patch_ready.blif file with bugs added and targets commented '''

if (len(sys.argv) == 2) and (sys.argv[1] in ["-h","-help","--help"]):
	print(usage)
	sys.exit(0)

bliffileInput = sys.argv[2]
try:
    brfhandle = open(bliffileInput,"r")
except IOError:
    print ("Couldn't open the file! Need an input mapped file at command line")

brfhandle.close()

'''
Count the total number of lines in the file
to randomly place the bugs
'''
def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

bfname, ext = os.path.splitext(bliffileInput)
bbaseFile   = bfname
bitWidth    = int(sys.argv[3])
nbugs	    = int(sys.argv[4])
bug_config  = int(sys.argv[5])
inpStr 	    = sys.argv[6]


fileLen = int(file_len(bliffileInput))
cmdstr  = ''
gname	= 'rg'
rseed 	= random.seed(time.time())
trgtloc = []

##new_n* starts from (input_width*2 + output_width + 1)
lbound = bitWidth*4+2 
##new_n* ends approximately at number of gates
##we will perform additonal check later to confirm and correct the upper bound
ubound = int(fileLen-float(lbound/4)-5+lbound)

subprocess.call(['cp {0}.blif {0}_0.blif'.format(bbaseFile)],shell=True,cwd=os.getcwd(),stdout=None)			
subprocess.call(['cp {0}.blif {0}_p0.blif'.format(bbaseFile)],shell=True,cwd=os.getcwd(),stdout=None)

def read_a_line(fhandle):

	#Handle empty lines with all kinds of spaces
	line = fhandle.readline()
	if line.rstrip():
		return line.strip().strip(';')
	else:
		return read_a_line(fhandle)

def iterate_bugs():

	slot = ((ubound-lbound)/nbugs)

	for bnu in range(0,nbugs):

		if bug_config == 1: # Closer to PIs
			pass
		else if bug_config == 2: # near mid
			pass
		else if bug_config == 3: # near POs
			pass
		else: #Random
			lbnd = lbound*(bnu+1) 
			ubnd = lbound*(bnu+1) + slot

		assert(lbnd >= lbound) 
		assert(ubnd <= ubound) 


		brfhandle  = open(bbaseFile+'_{}.blif'.format(bnu),'r')
		bprfhandle = open(bbaseFile+'_p{}.blif'.format(bnu),'r')
		bwfhandle  = open(bbaseFile+'_{}.blif'.format(bnu+1),'rw')
		bpwfhandle = open(bbaseFile+'_p{}.blif'.format(bnu+1),'rw')
		add_bug_blif(lbnd,ubnd,bnu,brfhandle,bwfhandle)
		add_bug_blif(lbnd,ubnd,bnu,bprfhandle,bpwfhandle,True)
		subprocess.call(['rm {0}_{1}.blif'.format(bbaseFile,bnu)],shell=True,cwd=os.getcwd())
		subprocess.call(['rm {0}_p{1}.blif'.format(bbaseFile,bnu)],shell=True,cwd=os.getcwd())

	subprocess.call(['mv {0}_{1}.blif {0}_{1}_{2}.blif'.format(bbaseFile,nbugs-1,'y')],shell=True,cwd=os.getcwd())
	subprocess.call(['mv {0}_p{1}.blif {0}_{1}_{2}.blif'.format(bbaseFile,nbugs-1,'pready')],shell=True,cwd=os.getcwd())

def add_bug_blif(lbnd,ubnd,bval,inpFile,outFile,patch=False):

	rs = '{}{}'.format(gname,bval)
	bugintA = ''
	bugintB = ''

	rnum = random.randint(lbnd,ubnd)
	bugout = 'new_n{rnum}_'

	if patch:
		patchstr = '#'
	else:
		patchstr = ''

	if bval == 1:
		outFile.write('# {}\n'.format(cmdstr))

	line = inpFile.readline()
	while '.gate' not in line:
		outFile.write(line)
		line = inpFile.readline()

	while '.end' not in line:
		# Assuming there are no spaces like A = n13 (should be A=n13), etc.
		# As the input file is coming from the push_button dir
		nets = line.split()

		#print nets;
		if ('A='+bugout in nets) or ('B='+bugout in nets):
			outFile.write('# '+line)
			for i in range(len(nets)):
				if nets[i] == 'A='+bugout:
					nets[i] = 'A={0}4'.format(rs)
				elif nets[i] == 'B='+bugout:
					nets[i] = 'B={0}4'.format(rs)
			outFile.write(' '.join(nets)+'\n')
		elif ('Y='+bugout in nets):
			trgtloc.append(bugout)
			gLen = len(nets)
			if gLen == 3: # Inverter/Buffer
				bugintA = nets[1].strip('A=')
				bugintB = bugintA
			else: # any 2-input gate
				bugintA = nets[1].strip('A=')
				bugintB = nets[2].strip('B=')
		else:
			outFile.write(line+'\n')

		line = inpFile.readline()

	outFile.write('.gate AND2X1   A={}3 B='.format(rs)+bugout+' Y={}4\n'.format(rs))
	outFile.write('.gate XOR2X1   A={0}2 B={0}0 Y={0}3\n'.format(rs))
	outFile.write('{}.gate XOR2X1   A={}1 B='.format(patchstr,rs)+bugintA+' Y={}2\n'.format(rs))
	outFile.write('.gate AND2X1   A='+bugintA+' B='+bugintB+' Y={}tmp1\n'.format(rs))
	outFile.write('.gate XOR2X1   A='+bugintA+' B='+bugintB+' Y={}tmp2\n'.format(rs))
	outFile.write('.gate XOR2X1   A={0}tmp1 B={0}tmp2 Y={0}1\n'.format(rs))
	outFile.write('.gate INVX1    A='+bugintA+' Y={}0\n'.format(rs))
	outFile.write('{}.end'.format(patchstr)+'\n')

	inpFile.close()

	if (bval == nbugs-1):
		outFile.seek(0)
		while True:
			if (line[0:7] == '.model'):
				
				break
			else:
				line = read_a_line(outFile)



	outFile.close()

	# Error if the selected target location is not found
	assert(len(trgtloc) == bval+1)

def main():

	iterate_bugs()



main()