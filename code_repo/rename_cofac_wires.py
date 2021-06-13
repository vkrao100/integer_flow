import sys
import subprocess
import time
import os

inpFile = open(sys.argv[1],'r')
rstr = sys.argv[2]

if sys.argv[1].strip().startswith('cofn'):
	nm = 'cfn' + sys.argv[1].lstrip('cofn')
else:
	nm = 'cfp' + sys.argv[1].lstrip('cofp')

outFile = open(nm,'w')

line = inpFile.readline()
while '.outputs' not in line:
	outFile.write(line)
	line = inpFile.readline()

outFile.write(line)
# print line
chk = line.strip().split()

# Assertion to ensure only one primary output
# assert(len(chk) == 2)

# out = chk[-1].strip()
# Assumption here is that the output names (target names) will never start with new
# which is assigned by abc
# count = 0
for line in inpFile.readlines():
	# print line
	if line[0:6] == '.names':
		line = line.strip()
		line = line.lstrip('.names').strip()
		# var = [x.strip() for x in line.split()]
		# if out in var:
		# 	# print var
		# 	count += 1
		# 	# Assert that out only occurs as an output in a .names
		# 	assert(var[-1] == out)
		# 	del var[-1]
		# 	line = (' ').join(var)
		# 	outFile.write('.names '+line.replace('new','new{}'.format(rstr))+' '+out+'\n')	
		# else:
		outFile.write('.names '+line.replace('new','new{}'.format(rstr))+'\n')	
	else:
		outFile.write(line)

# Assert that out only appears once
# assert(count == 1)

inpFile.close()
outFile.close()