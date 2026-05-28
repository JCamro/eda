#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Creando una cola de enteros vacía
    queue<int> q;
    // Mostrando la cola
    cout << "Elementos de la cola: ";
    // Verificar si está vacía
    if (q.empty()) {
        cout << "La cola esta vacia";
    }
    cout << endl;
    return 0;
}
