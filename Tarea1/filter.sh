#!/bin/bash

#Impresión de la lista filtrada por nombre, dominio y compañía
echo -e "Lista de James, con correo .org en Ad Astra: \n"  
grep ^James usuarios.csv | grep .org, | grep "Ad Astra" 

#Impresión de la lista filtrada por nombre y letra inicial del apellido 
echo -e "\n\nLista de James y Paul, con apellido empezado en J o S en Ad Astra: \n"
grep -e ^"James,J" -e ^"Paul,J" -e "James,S" -e "Paul,S"  usuarios.csv | grep "Ad Astra"

#Impresión de la cantidad de usuarios con nombre que inicia con J y su lista
echo -e "\n\nNumero de usuarios cuyo nombre empieza con J: $(grep ^"J" usuarios.csv | wc -l)"
echo -e "Numero de usuarios cuyo nombre empieza con J: $(grep ^"J" usuarios.csv | wc -l)" > usuariosJ.csv
grep ^"J" usuarios.csv >> usuariosJ.csv

#Cambio de instancias "mastercard" por "Mastercard"
sed -i 's/mastercard/Mastercard/g' usuarios.csv 

exit 0
#Marco Barquero (C30970), Andres Chacon (C32026)
