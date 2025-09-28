/*. Dada una lista de nombres de lugares turísticos (nombre, país), escriba módulos para:
a) Calcular la longitud de la lista.
b) Calcular la cantidad de ocurrencias de un país dado.
c) Obtener la lista inversa de 2 maneras distintas: intercambiando contenidos, y utilizando una estructura auxiliar.
d) Dado un país, generar una nueva lista con los nombres de sus lugares turísticos, si existe.
*/

#include <iostream>
#include <string>
using namespace std;

// 1. Definición de la estructura para un lugar turístico
struct LugarTuristico {
    string nombre;
    string pais;
    LugarTuristico* siguiente;
    LugarTuristico(string n, string p) : nombre(n), pais(p), siguiente(nullptr) {}
};

// 2. Insertar al final de la lista (módulo e)
void insertarFinal(LugarTuristico*& cabeza, string nombre, string pais) {
    LugarTuristico* nuevo = new LugarTuristico(nombre, pais);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        LugarTuristico* actual = cabeza;
        while (actual->siguiente) actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

// 3. Calcular la longitud de la lista (módulo a)
int longitudLista(LugarTuristico* cabeza) {
    int contador = 0;
    while (cabeza) {
        contador++;
        cabeza = cabeza->siguiente;
    }
    return contador;
}

// 4. Calcular ocurrencias de un país (módulo b)
int ocurrenciasPais(LugarTuristico* cabeza, string paisBuscado) {
    int contador = 0;
    while (cabeza) {
        if (cabeza->pais == paisBuscado) contador++;
        cabeza = cabeza->siguiente;
    }
    return contador;
}

// 5. Invertir la lista intercambiando contenidos (módulo c, método 1)
void invertirIntercambiando(LugarTuristico* cabeza) {
    // Contar nodos y guardar punteros en un arreglo
    int n = longitudLista(cabeza);
    LugarTuristico** nodos = new LugarTuristico*[n];
    LugarTuristico* actual = cabeza;
    for (int i = 0; i < n; i++) {
        nodos[i] = actual;
        actual = actual->siguiente;
    }
    // Intercambiar datos
    for (int i = 0; i < n / 2; i++) {
        swap(nodos[i]->nombre, nodos[n - 1 - i]->nombre);
        swap(nodos[i]->pais, nodos[n - 1 - i]->pais);
    }
    delete[] nodos;
}

// 6. Invertir la lista usando estructura auxiliar (módulo c, método 2)
LugarTuristico* invertirAuxiliar(LugarTuristico* cabeza) {
    LugarTuristico* nuevaCabeza = nullptr;
    while (cabeza) {
        LugarTuristico* nuevo = new LugarTuristico(cabeza->nombre, cabeza->pais);
        nuevo->siguiente = nuevaCabeza;
        nuevaCabeza = nuevo;
        cabeza = cabeza->siguiente;
    }
    return nuevaCabeza;
}

// 7. Generar lista de lugares de un país (módulo d)
LugarTuristico* lugaresDePais(LugarTuristico* cabeza, string paisBuscado) {
    LugarTuristico* nuevaCabeza = nullptr;
    LugarTuristico* ultimo = nullptr;
    while (cabeza) {
        if (cabeza->pais == paisBuscado) {
            LugarTuristico* nuevo = new LugarTuristico(cabeza->nombre, paisBuscado);
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

// 8. Mostrar la lista
void mostrarLista(LugarTuristico* cabeza) {
    while (cabeza) {
        cout << cabeza->nombre << " (" << cabeza->pais << ")\n";
        cabeza = cabeza->siguiente;
    }
}

// 9. Liberar memoria
void liberarLista(LugarTuristico* cabeza) {
    while (cabeza) {
        LugarTuristico* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// 10. Ejemplo de uso
int main() {
    LugarTuristico* lista = nullptr;
    insertarFinal(lista, "Machu Picchu", "Peru");
    insertarFinal(lista, "Torre Eiffel", "Francia");
    insertarFinal(lista, "Cristo Redentor", "Brasil");
    insertarFinal(lista, "Louvre", "Francia");

    cout << "Lista original:\n";
    mostrarLista(lista);

    cout << "\nLongitud de la lista: " << longitudLista(lista) << endl;
}