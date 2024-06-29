#!/bin/bash

clear
# Solicita al usuario que ingrese los valores
echo "INGRESE VALORES PARA LAS PRUEBAS"
read -p "El valor inicial de la cantidad de números a ordenar: " START_DIGITS
read -p "El valor final de la cantidad de números a ordenar: " END_DIGITS
read -p "El incremento de la cantidad de números entre el valor inicial y final: " INCREMENT
read -p "El número de pruebas por cada cantidad de números a ordenar: " TESTS_PER_DIGIT

# Verifica que los valores ingresados sean enteros
if ! [[ "$TESTS_PER_DIGIT" =~ ^[0-9]+$ ]] || ! [[ "$START_DIGITS" =~ ^[0-9]+$ ]] || ! [[ "$END_DIGITS" =~ ^[0-9]+$ ]] || ! [[ "$INCREMENT" =~ ^[0-9]+$ ]]; then
  echo "Error: Todos los valores deben ser enteros positivos."
  exit 1
fi

# Ejecuta los comandos de make
make re > /dev/null 2>&1 && make bonus > /dev/null 2>&1
cd testers > /dev/null

echo ""
echo "CHECKER TESTER WORKING..."
echo ""

# Bucle for con incremento personalizado
for ((digits = START_DIGITS; digits <= END_DIGITS; digits += INCREMENT)); do
  echo "Probando con $digits números..."
  
  for ((i = 0; i < $TESTS_PER_DIGIT; i++)); do

    Randomnbr=$(shuf -i 0-9999 -n $digits | tr '\n' ' ')
    
    ARG="$Randomnbr"
    
    RESULT=$(.././push_swap $ARG | .././checker $ARG)

    if [ "$RESULT" == "KO" ]; then
      echo "Prueba fallida con $digits números: $ARG"
      exit 1
    fi
  done
done

echo ""
echo "PRUEBAS EXITOSAS!"
cd ..
make fclean > /dev/null
