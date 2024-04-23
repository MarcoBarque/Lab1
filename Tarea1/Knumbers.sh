#!/bin/bash

times_f=4 #iteraciones de archivos (files)
count_f=0 #iterador de archivos
times_r=100 #iteraciones de randoms
count_r=1 #iterador de randoms

while [ "$count_f" -le $times_f ] #itera de 0 a 4 para los archivos
do
        count_r=1 #reinicia el iterador de randoms
        while [ "$count_r" -le $times_r ] #itera de 1 a 100 para tener 1000 randoms
        do
                if [ "$count_r" -eq 1 ] #Chequea si es el primero
                then
                        bash random.sh | head -13 | tail -10 > rand_"$count_f".dat #reescribe archivo
                else
                        bash random.sh | head -13 | tail -10 >> rand_"$count_f".dat #agrega al archivo
                fi
                let "count_r += 1" #Incrementa count_r
        done
        let "count_f += 1" #Incrementa count_r
done

exit 0
