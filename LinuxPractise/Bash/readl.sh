#!/bin/bash
i=1
while [[ $i -le 10 ]] ;
do
   echo "$i" >> out1.txt
  (( i += 1 ))
done
