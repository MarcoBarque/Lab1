
# ./matmult.x --l 1000 --B 1000 --n 1000 | tail -n 1 | cut -c 9-

times_d=16 #iteraciones de cantidad de datos
count_d=1 #iterador de datos

while [ "$count_d" -le 16 ] #itera de 0 a (times_f) para el numero de datos
do
        export OMP_NUM_THREADS=$count_d
        if [ "$count_d" -eq 1 ] #Chequea si es el primero
        then
		echo "$count_d" " $(./matmult.x --l 10000 --n 1000 --m 1000 | tail -n 1 | cut -c 9-)" > datosI.dat #reescribe archivo
        else
		echo "$count_d" " $(./matmult.x --l 10000 --n 1000 --m 1000 | tail -n 1 | cut -c 9-)" >> datosI.dat #agrega al archivo
        fi
	echo $count_d
        let "count_d += 1" #Incrementa count_d
done

times_i=16 #iteraciones de cantidad de threads
count_i=1 #iterador de threads

while [ "$count_i" -le 16 ] #itera de 0 a (times_i) para el numero de datos
do
        export OMP_NUM_THREADS=$count_i
        if [ "$count_i" -eq 0 ] #Chequea si es el primero
        then
		echo "$count_i" " $(./matmult_mkl.x --l 10000 --n 1000 --m 1000 | tail -n 1 | cut -c 9-)" > datosT.dat #reescribe archivo
        else
		echo "$count_i" " $(./matmult_mkl.x --l 10000 --n 1000 --m 1000 | tail -n 1 | cut -c 9-)" >> datosT.dat #agrega al archivo
        fi
	echo $count_i
        let "count_i += 1" #Incrementa count_d
done


exit 0
#Marco Barquero (C30970), Andres Chacon (C32026)
