#!/bin/bash
arr=("man" "bear" "pig" "dog" "cat" "sheep")
for ((counter=0; counter<${#arr[@]}; counter++))
do
	echo -n "${arr[$counter]}"
	printf "\n"
done
