#!/bin/bash

# ./matmult.x --l 1000 --B 1000 --n 1000 | tail -n 1 | cut -c 9-


times_d=5 #iteraciones de cantidad de datos
count_d=0 #iterador de datos

while [ "$count_d" -le $times_d ] #itera de 0 a (times_f) para el numero de datos
do
        echo $((10**$count_d))
	if [ "$count_d" -eq 0 ] #Chequea si es el primero
        then
		echo "$((10**$count_d))" " $(./matmult_tiem.x --l 1000 --n 1000 --m $((10**$count_d)) | tail -n 1 | cut -c 9-)" > datosI_it.dat #reescribe archivo
        else
		echo "$((10**$count_d))" " $(./matmult_tiem.x --l 1000 --n 1000 --m $((10**$count_d)) | tail -n 1 | cut -c 9-)" >> datosI_it.dat #agrega al archivo
        fi
        let "count_d += 1" #Incrementa count_d
done

times_i=5 #iteraciones de cantidad de threads
count_i=0 #iterador de threads

while [ "$count_i" -le $times_i ] #itera de 0 a (times_i) para el numero de datos
do
        echo $((10**$count_i))
	if [ "$count_i" -eq 0 ] #Chequea si es el primero
        then
                echo "$((10**$count_i))" " $(./matmult_tiem_mkl.x --l 1000 --n 1000 --m $((10**$count_i)) | tail -n 1 | cut -c 9-)" > datosT_it.dat #reescribe archivo
        else
		echo "$((10**$count_i))" " $(./matmult_tiem_mkl.x --l 1000 --n 1000 --m $((10**$count_i)) | tail -n 1 | cut -c 9-)" >> datosT_it.dat #agrega al archivo
        fi
        let "count_i += 1" #Incrementa count_i
done


exit 0
#Marco Barquero (C30970), Andres Chacon (C32026)
