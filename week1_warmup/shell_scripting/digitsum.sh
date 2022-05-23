#!/bin/bash

var=0
num=$1
while ((num > 0))
do
	var=$(($var+$num%10))
	num=$num/10
done
printf $var 
printf "\n"
