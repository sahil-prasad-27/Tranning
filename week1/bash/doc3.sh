#! /usr/bin/bash

echo "enter first string"
read st1
echo "enter second string"
read st2
if [ "$st1" == "$st2" ]
then
	echo "string matched"
else
	echo "string not matched"
fi
