/*Realizar un proceso que reciba una lista con datos sobre productos. De cada producto se
sabe el nombre y el stock. Se debe retornar la lista donde solamente figuren los productos cuyo stock
sea mayor que cero */

/*Realizar un proceso que reciba una lista con datos sobre productos. De cada producto se
sabe el nombre y el stock. Se debe retornar la lista donde solamente figuren los productos cuyo stock
sea mayor que cero */

#include <iostream>
#include <string>
using namespace std;

// Nodo de producto
struct Producto {
    string nombre;
    int stock;
    Producto* siguiente;
    Producto(string n, int s) : nombre(n), stock(s), siguiente(nullptr) {}
};

// Insertar al final de la lista
void insertarFinal(Producto*& cabeza, string nombre, int stock) {
    Producto* nuevo = new Producto(nombre, stock);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Producto* actual = cabeza;
        while (actual->siguiente) actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

// Mostrar la lista
void mostrarLista(Producto* cabeza) {
    while (cabeza) {
        cout << cabeza->nombre << " (Stock: " << cabeza->stock << ")\n";
        cabeza = cabeza->siguiente;
    }
}

// Retornar lista con productos cuyo stock > 0
Producto* filtrarStockPositivo(Producto* cabeza) {
    Producto* nuevaCabeza = nullptr;
    Producto* ultimo = nullptr;
    while (cabeza) {
        if (cabeza->stock > 0) {
            Producto* nuevo = new Producto(cabeza->nombre, cabeza->stock);
            if (!nuevaCabeza) {
                nuevaCabeza = nuevo;
                ultimo = nuevo;
            } else {
                ultimo->siguiente = nuevo;
                ultimo = nuevo;
            }
        }
        cabeza = cabeza->siguiente;
    }
    return nuevaCabeza;
}

// Liberar memoria
void liberarLista(Producto* cabeza) {
    while (cabeza) {
        Producto* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

int main() {
    Producto* lista = nullptr;
    insertarFinal(lista, "Arroz", 10);
    insertarFinal(lista, "Fideos", 0);
    insertarFinal(lista, "Aceite", 5);
    insertarFinal(lista, "Sal", 0);
    insertarFinal(lista, "Azucar", 3);

    cout << "Lista original:\n";
    mostrarLista(lista);

    Producto* listaFiltrada = filtrarStockPositivo(lista);

    cout << "\nLista con stock > 0:\n";
    mostrarLista(listaFiltrada);

    liberarLista(lista);
    liberarLista(listaFiltrada);
    return 0;
}


