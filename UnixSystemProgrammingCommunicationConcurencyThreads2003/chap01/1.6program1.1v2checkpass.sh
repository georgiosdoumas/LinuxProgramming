#!/bin/bash
# Prerequisite : there is an executable compiled with the following 
# gcc -Wall -o 1.6program1.1v2checkpass 1.6program1.1v2checkpass.c 
basicstr="mypass"
EXTRAINPUT=(a 6stuff 6stuffa 6stuffb 6stuffc 6stuffz 6stuffA 6stuffZ)
./1.6program1.1v2checkpass $basicstr  #this gives success
for word in ${EXTRAINPUT[*]}
do
  input=${basicstr}${word}  #all these inputs should not give success...
  # echo "---passing $input for checking --- "
  ./1.6program1.1v2checkpass $input  #for first 2 cases they fail as they should, but then again give successwhen they should not!
done
