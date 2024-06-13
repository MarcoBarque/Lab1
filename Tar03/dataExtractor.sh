#!/bin/bash

# ./mandelbrot | tail -n 1 | cut -c 9-


times_d=8 #iteraciones maximas
count_d=1 #iterador de datos

while [ "$count_d" -le $times_d ] #itera de 1 a (times_d)
do
	export OMP_NUM_THREADS=$count_d
        echo $count_d
	if [ "$count_d" -eq 1 ] #Chequea si es el primero
        then
		echo "$count_d" " $(./mandelbrot.x | tail -n 1 | cut -c 11-)" > datos.dat #reescribe archivo
        else
		echo "$count_d" " $(./mandelbrot.x | tail -n 1 | cut -c 11-)" >> datos.dat #agrega al archivo
        fi
        let "count_d += 1" #Incrementa count_d
done

gnuplot ploter.plt

exit 0
#Marco Barquero (C30970), Andres Chacon (C32026)
