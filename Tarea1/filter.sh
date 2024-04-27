#!/bin/bash

echo -e "Lista de James, con correo .org en Ad Astra \n"  
grep ^James usuarios.csv | grep .org, | grep "Ad Astra" 
#Impresión de la lista filtrada por nombre, dominio y compañía
                                                        
echo -e "\nLista de James y Paul, con apellido empezado en J o S en Ad Astra \n"
grep -e ^"James,J" -e ^"Paul,J" -e "James,S" -e "Paul,S"  usuarios.csv | grep "Ad Astra"
#Impresión de la lista filtrada por nombre y letra inicial del apellido 

echo -e "\n Numero de usuarios cuyo nombre empieza con J \n"
grep ^"J" usuarios.csv | wc -l
grep ^"J" usuarios.csv > usuariosJ.csv
#Impresión de la cantidad de usuarios con nombre que inicia con J y su lista

sed -i 's/mastercard/Mastercard/g' usuarios.csv 
#Cambio de instancias "mastercard" por "Mastercard"

exit 0
