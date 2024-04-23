#!/bin/bash

echo $"Lista de James, con correo .org en Ad Astra \n"
grep ^James usuarios.csv | grep .org, | grep "Ad Astra"

echo $"\nLista de James y Paul, con apellido empezado en J o S en Ad Astra \n"
grep -e ^"James,J" -e ^"Paul,J" -e "James,S" -e "Paul,S"  usuarios.csv | grep "Ad Astra"

echo $"\n Numero de usuarios cuyo nombre empieza con J \n"
grep ^"J" usuarios.csv | wc -l
grep ^"J" usuarios.csv > usuariosJ.csv

sed -i 's/mastercard/Mastercard/g' usuarios.csv 

exit 0
