#! /bin/bash

fruits=("Apple","Banana","cherry"."date")
index=0
# num=${#fruits[@]}

while [ "$index" -lt "${#fruits[@]}" ]; do
    echo "fruits at the index is : ${fruits[$index]}"
    ((index++))
done