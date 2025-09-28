/*Ejercicio 1. Diseñe la estructura de una lista que permita contener datos de algún tipo genérico.
a) Escriba un programa que lea una secuencia de números terminada en 999 y los almacene en una lista encadenada.
b) Utilizando la lista creada en a), implemente un módulo que reciba la lista y devuelva como resultado la cantidad de números
con 3 cifras.*/


#include <iostream>

using namespace std;

// Estructura de nodo genérico

//contiene a un nodo, que posee un puntero hacia al sigueinte, tal que si
/*Se define una estructura Nodo que puede almacenar cualquier tipo de dato (T).
Cada nodo tiene un dato y un puntero al siguiente nodo.
El constructor inicializa el dato y pone el puntero siguiente en nullptr.*/
template <typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

// Lista enlazada genérica


/*La clase Lista maneja una lista de nodos del tipo T.
cabeza apunta al primer nodo de la lista.
El constructor inicializa la lista vacía.
El método insertar agrega un nuevo nodo al inicio de la lista.
El método getCabeza retorna el puntero al primer nodo.
El destructor libera la memoria de todos los nodos.*/
template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;
public:
    Lista() : cabeza(nullptr) {}
/*Crea un nuevo nodo con el valor dado.
Lo enlaza al inicio de la lista*/
    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    Nodo<T>* getCabeza() const {
        return cabeza;
    }

    ~Lista() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            Nodo<T>* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

// Módulo para contar números de 3 cifras

/*Recorre la lista de enteros.
Cuenta cuántos valores tienen 3 cifras (entre 100 y 999).*/
int contarTresCifras(const Lista<int>& lista) {
    int contador = 0;
    Nodo<int>* actual = lista.getCabeza();
    while (actual) {
        int valor = actual->dato;
        if (valor >= 100 && valor <= 999) {
            contador++;
        }
        actual = actual->siguiente;
    }
    return contador;
}

int main() {
    Lista<int> lista;
    int numero;
    cout << "Ingrese numeros (999 para terminar):\n";
    while (true) {
    cin >> numero;
        if (numero == 999) break;
        lista.insertar(numero);
    }

    int cantidad = contarTresCifras(lista);
    cout << "Cantidad de numeros con 3 cifras: " << cantidad << std::endl;
    return 0;
}