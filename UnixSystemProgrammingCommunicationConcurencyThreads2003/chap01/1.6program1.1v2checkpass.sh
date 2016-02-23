#!/bin/bash
basicstr="mypass"
EXTRAINPUT=(a 6stuff 6stuffa 6stuffb 6stuffc 6stuffz 6stuffA 6stuffZ)
./1.6prog1.1v2 $basicstr  #this gives success
for word in ${EXTRAINPUT[*]}
do
  input=${basicstr}${word}  #all these inputs should not give success...
  # echo "---passing $input for checking --- "
  ./1.6prog1.1v2 $input  #for first 2 cases they fail , but then again give success
done
