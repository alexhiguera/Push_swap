<p align="center">
  <img src="https://raw.githubusercontent.com/ridaelfagrouch/push_swap_42/main/assets/push_swap.png" alt="Push_swap 42 project badge"/>
</p>

# Push swap
---
Push_swap es un proyecto de algoritmia de 42 escohol en el que debemos ordenar una lista determinada de números aleatorios con un conjunto limitado de instrucciones, utilizando el menor número posible de acciones.

## Uso
---
Clona el repositorio y entra en él con cd. Luego usa make para compilar.
```Bash
git clone git@github.com:alexhiguera/Push_swap.git
```
Despues corre esto:
```Bash
./push_swap <numbers>
```
Los números proporcionados pueden ser enteros positivos o negativos. No debe haber duplicados. Por ejemplo:
```Bash
./push_swap 6 0 -8776 2147483647 -2147483648
```
Si los argumentos son válidos, el programa mostrará la lista de acciones más eficiente para ordenar la lista.

El programa puede ser verificado con el comprobador proporcionado, de esta manera:
```Bash
ARG="5 7 9 2 -4"; ./push_swap $ARG | ./checker $ARG
```
También puedes simplemente hacer ``make test3``, ``make test5`` o ``make test100` para probar rápidamente el programa con ese número de valores a ordenar.

Puedes visualizar este algoritmo push_swap en acción con el [visualizador de push_swap de O-reo](https://github.com/o-reo/push_swap_visualizer)

# Reglas y la calificacón
---
El programa solo puede trabajar con dos pilas, la pila A y la pila B. Todos los números se suman inicialmente a la pila A y B está vacía.

Las posibles acciones son:
``pa`` (empujar A): toma el primer elemento en la parte superior de B y colócalo en la parte superior de A. No hagas nada si B está vacío.
``pb`` (empujar B): Tome el primer elemento en la parte superior de A y colóquelo en la parte superior de B. No haga nada si A está vacío.
``sa`` (intercambio A): intercambia los primeros 2 elementos en la parte superior de la pila A. No hagas nada si solo hay uno o ningún elemento.
``sb`` (intercambio B): intercambia los primeros 2 elementos en la parte superior de la pila B. No hagas nada si solo hay uno o ningún elemento.
``ss``: ``sa`` y ``sb`` al mismo tiempo.
``ra`` (rotar A): desplaza todos los elementos de la pila A hacia arriba en 1. El primer elemento se convierte en el último.
``rb`` (rotar B): desplaza todos los elementos de la pila B hacia arriba en 1. El primer elemento se convierte en el último.
``rr``: ra y rb al mismo tiempo.
``rra`` (rotación inversa A): desplaza todos los elementos de la pila A hacia abajo en 1. El último elemento se convierte en el primero.
``rrb`` (rotación inversa B): desplaza todos los elementos de la pila b hacia abajo en 1. El último elemento se convierte en el primero.
``rrr``: ``rra`` y ``rrb`` al mismo tiempo.

La calificación depende de qué tan eficiente sea el proceso de clasificación del programa.

- Clasificación 3 valores: no más de 3 acciones.
- Clasificación de 5 valores: no más de 12 acciones.
> Clasificación de 100 valores: calificación de 1 a 5 puntos según el número de acciones:
	- 5 puntos por menos de 700 acciones
	- 4 puntos por menos de 900
	- 3 puntos por menos de 1100
	- 2 puntos por menos de 1300
	- 1 punto por menos de 1500
  
> Clasificación de 500 valores: calificación de 1 a 5 puntos según el número de acciones:
	- 5 puntos por menos de 5500 acciones
	- 4 puntos por menos de 7000
	- 3 puntos por menos de 8500
	- 2 puntos por menos de 10000
	- 1 punto por menos de 11500