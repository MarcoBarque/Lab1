#!/bin/bash

TIME_c=4
count_c=0

while [ "$count_c" -le $TIME_c ]
do
	 if [ "$count_c" -eq 0 ]
	 then
		 cp rand_"$count_c".txt rand_c.txt
	 else 
		 cat rand_"$count_c".txt >> rand_c.txt
	 
	 fi

	 let "count_c += 1"
done

exit 0
