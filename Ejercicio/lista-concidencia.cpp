//dada una lista y un arreglo de 10 nunmeros, eliminar de la lista los elementos que existan en el arreglo

#include <iostream>
using namespace std;

// Nodo de la lista
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int v) : dato(v), siguiente(nullptr) {}
};

// Insertar al final de la lista
void insertarFinal(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente) actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

// Mostrar la lista
void mostrarLista(Nodo* cabeza) {
    while (cabeza) {
        cout << cabeza->dato << " ";
        cabeza = cabeza->siguiente;
    }
    cout << endl;
}

// Eliminar de la lista los elementos que existan en el arreglo
void eliminarCoincidencias(Nodo*& cabeza, int arr[], int n) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    while (actual) {
        bool encontrado = false;
        for (int i = 0; i < n; i++) {
            if (actual->dato == arr[i]) {
                encontrado = true;
                break;
            }
        }
        if (encontrado) {
            Nodo* temp = actual;
            if (anterior) {
                anterior->siguiente = actual->siguiente;
            } else {
                cabeza = actual->siguiente;
            }
            actual = actual->siguiente;
            delete temp;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

// Liberar memoria
void liberarLista(Nodo* cabeza) {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    Nodo* lista = nullptr;
    // Ejemplo: insertar algunos números en la lista
    insertarFinal(lista, 5);
    insertarFinal(lista, 12);
    insertarFinal(lista, 7);
    insertarFinal(lista, 20);
    insertarFinal(lista, 3);
    insertarFinal(lista, 8);

    int arreglo[10] = {3, 7, 8, 9, 10, 12, 15, 18, 20, 25};

    cout << "Lista original: ";
    mostrarLista(lista);

    eliminarCoincidencias(lista, arreglo, 10);

    cout << "Lista tras eliminar coincidencias: ";
    mostrarLista(lista);

    liberarLista(lista);
    return 0;
}