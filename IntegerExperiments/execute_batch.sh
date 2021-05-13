#!/bin/bash

PATH=~/Desktop/IntegerExperiments/:$PATH

# Declare array
declare -a ARRAY

# Link filedescriptor 10 with stdin
exec 10<&0

# stdin replaced with a file supplied as a first argument
exec < execute.txt
let count=0

while read LINE; do
    ARRAY[$count]=$LINE
    ((count++))
done

echo Number of files to be executed: ${#ARRAY[@]}

# echo array's content
echo ${ARRAY[@]}
for (( i = 0; i < count; i++ )); do
	/usr/bin/time -v Singular ${ARRAY[i]} --no-warn 2>&1 | tee -a ${ARRAY[i]}.txt
done 


# restore stdin from filedescriptor 10
# and close filedescriptor 10
exec 0<&10 10<&-