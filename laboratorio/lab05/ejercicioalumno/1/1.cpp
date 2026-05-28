#include <iostream>
#include <queue> 

using namespace std;

// Función auxiliar para mostrar el estado actual de la cola
void mostrarCola(priority_queue<int> cola) {
    if (cola.empty()) {
        cout << "La cola está vacía." << endl;
        return;
    }
    
    while (!cola.empty()) {
        cout << "[" << cola.top() << "] ";
        cola.pop(); 
    }
    cout << endl;
}

int main() {
    // 1. Crear la cola de prioridad
    priority_queue<int> miCola;

    // 2. Ingresar los valores: 10, 20 y 15
    miCola.push(10);
    miCola.push(20);
    miCola.push(15);
    miCola.push(9);

    // 3. Mostrar los elementos ingresados
    cout << "Estado inicial de la cola (orden de prioridad):" << endl;
    mostrarCola(miCola);

    // 4. Eliminar el elemento con mayor prioridad (el 20)
    cout << "\nEliminando el elemento con mayor prioridad: " << miCola.top() << endl;
    miCola.pop();

    // 5. Mostrar el estado resultante
    cout << "Estado resultante de la cola:" << endl;
    mostrarCola(miCola);

    return 0;
}


 