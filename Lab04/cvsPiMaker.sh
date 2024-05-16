#!/bin/bash


times_d=10 #iteraciones de cantidad de datos
count_d=0 #iterador de datos

while [ "$count_d" -le $times_d ] #itera de 0 a (times_f) para el numero de datos
do
        if [ "$count_d" -eq 0 ] #Chequea si es el primero
        then
		./pi.x --n $((10 ** count_d)) > datosI.dat #reescribe archivo
        else
		./pi.x --n $((10 ** count_d)) >> datosI.dat #agrega al archivo
        fi
        let "count_d += 1" #Incrementa count_d
done

times_i=8 #iteraciones de cantidad de threads
count_i=1 #iterador de threads

while [ "$count_i" -le $times_i ] #itera de 0 a (times_i) para el numero de datos
do
        export OMP_NUM_THREADS=$count_i
	if [ "$count_i" -eq 1 ] #Chequea si es el primero
        then
                ./pi.x --n $((10 ** 9)) > datosT.dat #reescribe archivo
        else
                ./pi.x --n $((10 ** 9)) >> datosT.dat #agrega al archivo
        fi
        let "count_i += 1" #Incrementa count_i
done


exit 0
#Marco Barquero (C30970), Andres Chacon (C32026)
