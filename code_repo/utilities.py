############################################################################################################
# Author : Vikas
# Intent   - To add Don't care logic with a bug at random 
#		  	nets in the input blif files.
# Usage -   'python {0}utilities.py {1} {2} {3} {4} {5}'num_trgts, bug_config, inpStr)
# 	    -   0 - src_path
#		- 	1 - base file (blif)
#		- 	2 - bit width
#		- 	3 - number of targets (number of bugs)
#		- 	4 - bug_config - look at the code for config explanations
#		-	5 - input string name for redundant gate names
# Notation - rg - redundant_gate
#          - gb - gate bug
# Outputs  - Dump a *.blif file with bugs added at the specified gates
#          - Dump a *_patch_ready.blif file with bugs added and targets commented
##############################################################################################################

import sys
import subprocess
import time
import os
import re
import random
import pdb



usage = ''' # Author : Vikas
# Intent   - To add Don't care logic with a bug at random 
#		  	nets in the input blif files.
# Usage -   'python {0}utilities.py {1} {2} {3} {4} {5}'num_trgts, bug_config, inpStr)
# 	    -   0 - src_path
#		- 	1 - base file (blif)
#		- 	2 - bit width
#		- 	3 - number of targets (number of bugs)
#		- 	4 - bug_config - look at the code for config explanations
#		-	5 - input string name for redundant gate names (example: 'rg','gb')
# Notation - rg - redundant_gate
#          - gb - gate_bug
# Outputs  - Dump a *.blif file with bugs added at the specified gates
#          - Dump a *_patch_ready.blif file with bugs added and targets commented '''

if (len(sys.argv) == 2) and (sys.argv[1] in ["-h","-help","--help"]):
	print(usage)
	sys.exit(0)

bliffileInput = sys.argv[1]
try:
    brfhandle = open(bliffileInput,"r")
except IOError:
    print ("Couldn't open the file! Need an input mapped file at command line")

'''
Count the total number of lines in the file
to randomly place the bugs
'''
def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

def read_a_line(fhandle):

	#Handle empty lines with all kinds of spaces
	line = fhandle.readline()
	if line.rstrip():
		return line.strip().strip(';')
	else:
		return read_a_line(fhandle)

def find_a_trgt_node(lb,ub,ih):
	
	global trgtloc
	global node_name_not_settled
	global found
	foundNet = False
	nstr = ''
	#Check if the node names are n* or new_n*_
	if node_name_not_settled:
		line = read_a_line(ih)
		while '.gate' not in line:
			line = ih.readline().strip()
		# Hopefully the nodenames occur within first 10 lines and doesn't change
		for _ in range(10): 
			nets = line.split()
			if any('new_n' in net for net in nets) and (not found):
				found = True
			line = ih.readline().strip()
		#Only run this loop first time
		node_name_not_settled = False
		#Pull back the handler to beginning of file
		ih.seek(0)

	while True:
		rnum = random.randint(lb,ub)
		# print ("{}:{}:{}".format(lb,ub,rnum))
		# Some blifs have internal nodes as n*
		#Some blifs have internal nodes as new_n*_
		if found:
			onode = 'new_n{}_'.format(rnum)
		else:
			onode = 'n{}'.format(rnum)

		if onode not in trgtloc:
			break

	line = ih.readline()
	while '.gate' not in line:
		line = ih.readline()

	while '.end' not in line:
		nets = line.split()
		if ('Y='+onode in nets):
			foundNet = True
			trgtloc.append(onode)
			gLen = len(nets)
			if gLen == 4: # Inverter/Buffer
				i1node = nets[2].strip('A=')
				i2node = i1node
			else: # any 2-input gate
				i1node = nets[2].strip('A=')
				i2node = nets[3].strip('B=')
			break
		line = ih.readline()
	ih.seek(0)
	if not foundNet:
		onode, i1node, i2node = find_a_trgt_node(lb,ub,ih)

	return onode, i1node, i2node

'''
Global variables and command line arguments
'''
bfname, ext = os.path.splitext(bliffileInput)
bbaseFile   = bfname
bitWidth    = int(sys.argv[2])
nbugs	    = int(sys.argv[3])
bug_config  = int(sys.argv[4])
inpStr 	    = sys.argv[5]
node_name_not_settled = True
found = False

fileLen = int(file_len(bliffileInput))
cmdstr  = ''
gname	= 'rg'
rseed 	= random.seed(time.time())
trgtloc = []


##new_n* starts from (input_width*2 + output_width + 1)
lbound = bitWidth*4+2 

## fileLen - total number of lines
## 4 - (comment/model/inp/out/end)
## lbound - since the naming starts from inp+out+1 (lbound)
## lbound/2 - atleast 2*n nodes are outputs in gates (doesn't need new int nodes)
## new_n* ends approximately at number of gates
## we will perform additonal check later to confirm and correct the upper bound
ubound = int(fileLen-(lbound/2)-5+lbound)

subprocess.call(['cp {0}.blif {0}_0.blif'.format(bbaseFile)],shell=True,cwd=os.getcwd(),stdout=None)			
subprocess.call(['cp {0}.blif {0}_p0.blif'.format(bbaseFile)],shell=True,cwd=os.getcwd(),stdout=None)

def iterate_bugs():

	# Number of possible slots given the bounds
	slot = ((ubound-lbound)/nbugs)
	lbnd = 0
	ubnd = 0

	for bnu in range(0,nbugs):

		# <n(lbound)..n(lbound+slot)> -- <n(ubound-slot)..n(ubound)>
		# <-------first slot ------->
		#                                <-------last slot -------->

		# As slot width increases - the bug is more likely
		# to be placed (spread across) middle columns. In those cases,
		# Verification using amulet doesn't complete even for 2 bugs
		# Hence, limiting slot to under 1000 for exps.
		if (bug_config == 1): # All bugs within the first slot
			if slot > 400:
				slot = 400
 			lbnd = lbound  
			ubnd = lbound + slot
		elif (bug_config == 2): # random bug placement
			lbnd = lbound + slot*(bnu) 
			ubnd = lbound + slot*(bnu+1)
		elif bug_config == 2: # near PI's
			pass
		elif bug_config == 3: # near mid
			pass
		elif bug_config == 4: # near PO's
			pass
		else: #Random
			lbnd = lbound + slot*(bnu) 
			ubnd = lbound + slot*(bnu+1) 

		# print ("{}:{}:{}:{}".format(lbnd,ubnd,lbound,ubound))
		assert(lbnd >= lbound) 
		assert(ubnd <= ubound) 


		brfhandle  = open(bbaseFile+'_{}.blif'.format(bnu),'r')
		bprfhandle = open(bbaseFile+'_p{}.blif'.format(bnu),'r')
		bwfhandle  = open(bbaseFile+'_{}.blif'.format(bnu+1),'w')
		bpwfhandle = open(bbaseFile+'_p{}.blif'.format(bnu+1),'w')
		setup_bug(lbnd,ubnd,bnu,brfhandle,bwfhandle,bprfhandle,bpwfhandle)
		subprocess.call(['rm {0}_{1}.blif'.format(bbaseFile,bnu)],shell=True,cwd=os.getcwd())
		subprocess.call(['rm {0}_p{1}.blif'.format(bbaseFile,bnu)],shell=True,cwd=os.getcwd())

	#Update target locations in the model line for reference
	brfhandle  = open('{}_{}.blif'.format( bbaseFile,nbugs),'r')
	bprfhandle = open('{}_p{}.blif'.format(bbaseFile,nbugs),'r')
	bwfhandle  = open('{}_{}_{}.blif'.format( bbaseFile,nbugs,'y'),'w')
	bpwfhandle = open('{}_p{}_{}.blif'.format(bbaseFile,nbugs,'pready'),'w')
	
	lines = brfhandle.readlines()
	tmp = lines[0].strip()
	lines[0] = '# {} '.format(' '.join(trgtloc)) + tmp + '\n'
	bwfhandle.writelines(lines)
	brfhandle.close()
	bwfhandle.close()
	
	lines = bprfhandle.readlines()
	tmp = lines[0].strip()
	lines[0] = '# {} '.format(' '.join(trgtloc)) + tmp + '\n'
	bpwfhandle.writelines(lines)	

	bprfhandle.close()
	bpwfhandle.close()
	subprocess.call(['rm {0}_{1}.blif'.format(bbaseFile,nbugs)],shell=True,cwd=os.getcwd())
	subprocess.call(['rm {0}_p{1}.blif'.format(bbaseFile,nbugs)],shell=True,cwd=os.getcwd())

def add_bug(bugout, bugintA, bugintB, bval, inpFile, outFile, patch=False):

	rs = '{}{}'.format(gname,bval)

	if patch:
		patchstr = '#'
	else:
		patchstr = ''

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
		else:
			outFile.write(line)

		line = inpFile.readline()


	if bval%2 == 0: #Even number - rectify at rg*3
		outFile.write('.gate AND2X1   A={}3 B='.format(rs)+bugout+' Y={}4\n'.format(rs))
		outFile.write('{0}.gate XOR2X1   A={1}2 B={1}0 Y={1}3\n'.format(patchstr,rs))
	else: #Rectify at rg*4
		outFile.write('{0}.gate AND2X1   A={1}3 B='.format(patchstr,rs)+bugout+' Y={}4\n'.format(rs))
		outFile.write('.gate XOR2X1   A={0}2 B={0}0 Y={0}3\n'.format(rs))

	#Always rectify at rg*2
	# outFile.write('.gate AND2X1   A={}3 B='.format(rs)+bugout+' Y={}4\n'.format(rs))
	# outFile.write('.gate XOR2X1   A={0}2 B={0}0 Y={0}3\n'.format(rs))
	# outFile.write('{0}.gate XOR2X1   A={1}1 B='.format(patchstr,rs)+bugintA+' Y={}2\n'.format(rs))

	outFile.write('.gate XOR2X1   A={}1 B='.format(rs)+bugintA+' Y={}2\n'.format(rs))
	outFile.write('.gate AND2X1   A='+bugintA+' B='+bugintB+' Y={}tmp1\n'.format(rs))
	outFile.write('.gate XOR2X1   A='+bugintA+' B='+bugintB+' Y={}tmp2\n'.format(rs))
	outFile.write('.gate XOR2X1   A={0}tmp1 B={0}tmp2 Y={0}1\n'.format(rs))
	outFile.write('.gate INVX1    A='+bugintA+' Y={}0\n'.format(rs))
	outFile.write('{}.end'.format(patchstr)+'\n')

	inpFile.close()
	outFile.close()

	# Error if the selected target location is not found at every step
	assert(len(trgtloc) == bval+1)

def setup_bug(lbnd,ubnd,bval,inpFile,outFile,pinpFile,poutFile):

	bugout = ''
	bugintA = ''
	bugintB = ''

	bugout, bugintA, bugintB = find_a_trgt_node(lbnd,ubnd,inpFile)

	add_bug(bugout, bugintA, bugintB,bval,inpFile,outFile)
	add_bug(bugout, bugintA, bugintB,bval,pinpFile,poutFile,True)

def main():

	iterate_bugs()



main()