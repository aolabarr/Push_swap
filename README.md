# Push swap

## Descripción

Este proyecto es parte del 42 cursus y se llama **push swap**. El objetivo es trabajar algorítmos de ordenación y su optimización. No se busca tanto la optimización computacional sino la eficiencia en realizar la menor cantidad de ordenes necesarias para conseguir el objetivo, que es ordenar una lista de números introducidos como argumentos al programa. Por otro lado, tambien se ha realizado un checker en la parte _bonus_ del proyecto. El checker es un programa que verifica si una lista de ordenes es capaz de dar como resultado la lista finalmente ordenada. Para mas detalle, se recomienta leer el enunciado del proyecto en el _subject.pdf_

## Compilación

Para compilar el programa push swap, usa comando ```make```. Tambien se puede recompilar con ```make re``` y para compilar el checker ```make bonus```. Para borrar los objetos y el ejecutable```make fclean```.

## Ejecución

El programa push swap se ejecuta introduciendo una lista de números como argumentos. La lista de números se puede poner dentro de comillas para que el programa lo recoja solo como un argumento o sin comillas, que de esta forma los tratará como varios argumentos. Por ejemplo:

```sh
./push_swap 42 800 -300 12 1240 35
```
Por otro lado, se puede utilizar el checker para la comprobación de la siguiente forma. El checker dara un ```OK``` si la lista es ordenada de forma correcta o un ```KO``` si el programa no es capaz de ordenarla:
```sh
ARG="42 800 -300 12 1240 35"; ./push_swap $ARG | ./checker $ARG
```

## Testers

Además se ponen a disposición sendos scripts para realizar pruebas de comprobación de los programas. Para comprobar el push swap se utiliza el tester realizado por [Julien Caucheteux](https://github.com/julien-ctx), que lo se puede encontrar en este [enlace](https://github.com/julien-ctx/push-swap-tester). Para ejecutar el tester del push swap:
```sh
./testers/push_swap_tester.sh
```
Para ejecutar el tester del checker:
```sh
./testers/checker_tester.sh
```
