#!/bin/bash

#make: 
      cd .. 
      make re && make bonus
      cd testers
      clear


TESTS_PER_DIGIT=10


START_DIGITS=500
END_DIGITS=505

for digits in $(seq $START_DIGITS $END_DIGITS); do
  echo "Probando con $digits dígitos..."
  
  for ((i = 0; i < $TESTS_PER_DIGIT; i++)); do

    Randomnbr=$(shuf -i 0-9999 -n $digits | tr '\n' ' ')
    
    ARG="$Randomnbr"
    
    RESULT=$(.././push_swap $ARG | .././checker $ARG)

    if [ "$RESULT" == "KO" ]; then
      echo "Prueba fallida con $digits dígitos: $ARG"
      exit 1;
    fi
  done
done
echo "Pruebas exitosas!"