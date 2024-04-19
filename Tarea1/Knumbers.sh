#!/bin/bash

TIMES_r=100
TIMES_f=4
count_f=0

while [ "$count_f" -le $TIMES_f ]
do
	count_r=1
	while [ "$count_r" -le $TIMES_r ]
	do
		if [ "$count_r" -eq 1 ]
		then 
			bash random.sh | head -13 | tail -10 >  rand_"$count_f".dat
		else
			bash random.sh | head -13 | tail -10 >>  rand_"$count_f".dat
		fi
		let "count_r += 1"	
	done
	let "count_f += 1"
done	

exit 0
