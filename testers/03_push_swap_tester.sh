#!/bin/bash

#make:
	cd ..
	make re
	cp -r testers/push_swap_tester/ ./push_swap_tester/
	cd push_swap_tester
	clear

	bash basic_test.sh

	# Solicitar confirmación al usuario
	read -p "¿Deseas seguir con la siguiente prueba? (y/N): " respuesta
	respuesta=${respuesta,,} # Convertir la respuesta a minúsculas
	#Verificar la respuesta del usuario
	if [[ "$respuesta" != "y" ]]; then
	 	echo "Ejecución de la prueba cancelada."
		exit 1
	fi
	
	echo "Pruebas con 3 números..."
	bash loop.sh 3 10
	read -p "¿Seguir con 5 números? (y/N): " respuesta
	respuesta=${respuesta,,} # Convertir la respuesta a minúsculas
	if [[ "$respuesta" != "y" ]]; then
	 	echo "Ejecución de la prueba cancelada."
		exit 1
	fi

	echo "Pruebas con 5 números..."
	bash loop.sh 5 10
	read -p "¿Seguir con 100 números? (y/N): " respuesta
	respuesta=${respuesta,,} # Convertir la respuesta a minúsculas
	if [[ "$respuesta" != "y" ]]; then
	 	echo "Ejecución de la prueba cancelada."
		exit 1
	fi
	
	echo "Pruebas con 100 números..."
	bash loop.sh 100 5
	read -p "¿Seguir con 500 números? (y/N): " respuesta
	respuesta=${respuesta,,} # Convertir la respuesta a minúsculas
	if [[ "$respuesta" != "y" ]]; then
	 	echo "Ejecución de la prueba cancelada."
		exit 1
	fi
	echo "Pruebas con 500 números..."
	
	bash loop.sh 500 5

	#bash debug.sh random 10

	bash clean.sh

	cd ..
	rm -r push_swap_tester/
	make fclean > /dev/null 2>&1

	echo ""
	echo "TEST FINALIZADA y LIMPIEZA REALIZADA."
	echo ""