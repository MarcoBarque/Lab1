#!/bin/bash

times_c=4 #Valor maximo para el iterador
count_c=0 #Contador desde 0

while [ "$count_c" -le $TIME_c ] #Realiza la iteracion de 0 a 4
do
	 if [ "$count_c" -eq 0 ] #Chequea si es la primera iteracion
	 then
		 cp rand_"$count_c".dat rand_c.dat #Crea/sobreescribe el archivo
	 else 
		 cat rand_"$count_c".dat >> rand_c.dat #Anexa datos al archivo
	 fi

	 let "count_c += 1" #Aumenta el contador en 1
done

exit 0
#Marco Barquero (C30970), Andres Chacon (C32026)
