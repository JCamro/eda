#include <iostream>
using namespace std;

// Estructura para los nodos de la lista doblemente enlazada
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

// Función global para insertar nodos de forma ordenada al final
void insertarAlFinal(Nodo*& cabeza, Nodo*& cola, int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }
}

// Función global para liberar la memoria dinámica de toda la lista
void liberarLista(Nodo*& cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temporal = actual;
        actual = actual->siguiente;
        delete temporal;
    }
    cabeza = nullptr;
}

int main() {
    Nodo* cabeza = nullptr;
    Nodo* cola = nullptr;

    // Llenar la lista con los elementos del 1 al 10
    for (int i = 1; i <= 10; ++i) {
        insertarAlFinal(cabeza, cola, i);
    }

    // Mostrar los elementos de inicio a fin
    cout << "Lista en direccion directa (1 al 10):" << endl;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << "\n\n";

    // Mostrar los elementos de fin a inicio
    cout << "Lista en direccion inversa (10 al 1):" << endl;
    actual = cola;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->anterior;
    }
    cout << endl;

    // Limpieza de memoria obligatoria antes de finalizar
    liberarLista(cabeza);

    return 0;
}
