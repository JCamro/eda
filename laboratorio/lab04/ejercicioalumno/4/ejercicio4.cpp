#include <iostream>

using namespace std;

struct Node {
    int dato;
    Node* siguiente;
};

int main() {
    Node* cabeza = nullptr;
    Node* cola = nullptr;

    // Crear la lista circular del 1 al 12
    for (int i = 1; i <= 12; ++i) {
        Node* nuevo = new Node();
        nuevo->dato = i;

        if (cabeza == nullptr) {
            cabeza = nuevo;
            cola = nuevo;
            nuevo->siguiente = cabeza; // Se apunta a sí mismo al inicio
        } else {
            cola->siguiente = nuevo;   // El viejo último apunta al nuevo
            cola = nuevo;              // El nuevo pasa a ser la cola
            cola->siguiente = cabeza;  // La nueva cola se cierra con la cabeza
        }
    }

    // Recorrer la lista para verificar la circularidad
    Node* actual = cabeza;
    cout << "Lista circular (dando una vuelta completa): " << endl;
    
    // Usamos un bucle do-while porque el inicio y el fin coinciden en la cabeza
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    
    cout << cabeza->dato << " (Volvio al inicio)" << endl;

    // Liberar la memoria rompiendo el ciclo primero
    cola->siguiente = nullptr; 
    actual = cabeza;
    while (actual != nullptr) {
        Node* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    return 0;
}
