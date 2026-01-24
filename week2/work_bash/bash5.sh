#! /bin/bash

num=1
while [ $num -le 10 ]
do
    if [ $num -eq 2 ]
    then
        
        num=$(( num+1 ))
        continue
    fi
    echo "$num"
    
    num=$(( num+1 ))
done