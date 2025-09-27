## Structs
un **registro** o **struct** agrupa campos heterogéneos bajo un mismo nombre — p. ej. datos de un empleado: legajo, nombre, dirección, sueldo, antigüedad. Esto aparece en tu PDF como la forma natural de representar “una fila” de datos complejos. 

## Punteros 
Definición: un puntero es una variable que almacena una dirección de memoria. En C++ se declara con T *p;. El operador & obtiene la dirección de una variable; el operador * desreferencia el puntero (accede al objeto apuntado).

**Referencia**
○ Hace que un puntero apunte a una variable
○ Ejemplo:
● int i = 40;
● int *p = &i;

**Indirección**
○ Permite acceder al valor que hay en la memoria a la
que apunta un puntero
○ Ejemplo: printf(“%d”, *p);


**VENTAJAS DE LOS PUNTEROS**
Cada elemento se maneja de la misma forma que una matriz de
dos dimensiones, pero sin desperdiciar espacios de memoria. 




## IMPLEMENTACIÓN DE COLAS

**caracteristicas**

● Los elementos son del mismo tipo. Esto
convierte a la cola en una estructura
homogénea.
● Los elementos pueden recuperarse en el orden
en que fueron almacenados. Por esto, la cola
tiene forma de acceso a la estructura
denominada FIFO
● La cantidad de elementos que contiene una
cola puede variar a lo largo de la ejecución del
programa. Por lo cual es una estructura
dinámica.


**operaciones basicas**
● Creación → q_create ();
● Agregar un elemento → q_push ( var_cola, elem);
● Quitar un elemento → q_pop( var_cola );
● Devolver el primer elemento → q_top( var_cola );
● Devolver el último → q_bottom( var_cola );
● Devolver si está vacía → q_empty( var_cola );
● Devolver el # de elementos → q_length( var_cola);
● Creación → q_create ();
● Agregar un elemento → q_push ( var_cola, elem);
● Quitar un elemento → q_pop( var_cola );
● Devolver el primer elemento → q_top( var_cola );
● Devolver el último → q_bottom( var_cola );
● Devolver si está vacía → q_empty( var_cola );
● Devolver el # de elementos → q_length( var_cola)


## IMPLEMENTACIOS DE PILAS
● Los elementos son del mismo tipo. Esto
convierte a la pila en una estructura
homogénea.
● Los elementos pueden recuperarse en el orden
inverso en que fueron almacenados. Por esto,
la pila tiene forma de acceso a la estructura
denominada LIFO
● La cantidad de elementos que contiene una
pila puede variar a lo largo de la ejecución del
programa. Por lo cual es una estructura
dinámica.

**operaciones básicas**
● Creación → St_create ();
● Agregar un elemento → St_push ( var_pila,
elem);
● Quitar un elemento → St_pop( var_pila );
● Devolver el primer elemento → St_top( var_pila
);
● Devolver si está vacía → St_empty( var_pila );
●Devolverel#deelementos→Stlength(
● Creación → St_create ();
● Agregar un elemento → St_push ( var_pila,
elem);
● Quitar un elemento → St_pop( var_pila );
● Devolver el primer elemento → St_top( var_pila
);
● Devolver si está vacía → St_empty( var_pila );
● Devolver el # de elementos → St_length(
var_pila );


## LISTAS SIMPLES

**● ¿Qué es una lista?**
○ Para almacenar de una forma organizada un conjunto de
datos homogéneos se dispone de arreglos.
○ ¿Qué pasa si no se conoce la “cantidad” de elementos?
○ Lista → tipos de datos dinámicos que se construyen con nodos.
○ Nodos → registro de dos campos: dato y enlace
○ Una lista enlazada es → una colección de nodos ordena según
su posición, tal que cada uno de ellos es accedido mediante el
campo de enlace del nodo anterior

**PUNTEROS**
● Me sirven para saber a donde apunta una arista y que contiene el nodo.
● Es un espacio de memoria

**CABEZA**
● Se que es el primer elemento
● Nadie hace referencia a la
cabeza
● Es el primer nodo a crear. 

**NODO**
● Dentro del nodo hay datos, los cuales quiero modelar
● Es una estructura en si misma
● Sabemos que alguien apunta a él o no, sabemos que el puede
apuntar a otro nodo o no. Dependiendo en que parte esta parado el
observador. 

**ARISTA**
● Es una representación de como alcanzo al siguiente nodo, cual es el puntero al siguiente. 

**COLA**
● No va a apuntar a ningún otro nodo, pues es el último.
● Es un nodo
● Su puntero a siguiente tiene que ser nulo

**CONCLUSIONES**

● Una lista es una estructura lineal
dinámica.
● Los datos no necesariamente residen en
posiciones consecutivas de la memoria.
● La mayor facilidad → enganche dinámico
○ Permite intercalado o borrado “sencillo” de información sin movimiento masivo de datos en