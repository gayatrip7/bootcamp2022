#!/bin/bash

mkdir root
cd root
for ((count=1;count<6;count++))
do
	mkdir dir$count
	cd dir$count
	for ((num=1;num<5;num++))
	do
		for((loop=1;loop<5;loop++))
		do
			echo "$loop" >> file$loop
		done
	done
	cd ..
done
