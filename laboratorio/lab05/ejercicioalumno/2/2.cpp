#include <iostream>
#include <stack> // Librería para el uso de pilas

using namespace std;

class ColaConPilas {
private:
    stack<int> pila1; // Se usa para la operación enqueue (ingreso)
    stack<int> pila2; // Se usa para la operación dequeue (extracción)

public:
    // Operación Enqueue: Inserta un elemento al final de la cola
    void enqueue(int x) {
        pila1.push(x);
        cout << "Insertado: " << x << endl;
    }

    // Operación Dequeue: Elimina y retorna el elemento al frente de la cola
    int dequeue() {
        // Si ambas pilas están vacías, la cola está vacía
        if (pila1.empty() && pila2.empty()) {
            cout << "Error: La cola está vacía." << endl;
            return -1; 
        }

        // Si la pila2 está vacía, transferimos todos los elementos de pila1
        if (pila2.empty()) {
            while (!pila1.empty()) {
                pila2.push(pila1.top()); // Pasamos el de arriba
                pila1.pop();             // Lo eliminamos de la pila1
            }
        }

        // El elemento en la cima de pila2 es el frente de la cola
        int elementoFrente = pila2.top();
        pila2.pop();
        return elementoFrente;
    }

    // Función auxiliar para verificar si la cola está vacía
    bool estaVacia() {
        return pila1.empty() && pila2.empty();
    }
};

int main() {
    ColaConPilas miCola;

    cout << "--- Insertando elementos (Enqueue) ---" << endl;
    miCola.enqueue(10);
    miCola.enqueue(20);
    miCola.enqueue(30);

    cout << "\n--- Extrayendo elementos (Dequeue) ---" << endl;
    // Debe salir en orden FIFO: 10, luego 20, luego 30
    cout << "Desencolado: " << miCola.dequeue() << endl;
    cout << "Desencolado: " << miCola.dequeue() << endl;

    cout << "\n--- Insertando un nuevo elemento ---" << endl;
    miCola.enqueue(40);

    cout << "\n--- Extrayendo los elementos restantes ---" << endl;
    cout << "Desencolado: " << miCola.dequeue() << endl; // Debe salir 30
    cout << "Desencolado: " << miCola.dequeue() << endl; // Debe salir 40

    return 0;
}
