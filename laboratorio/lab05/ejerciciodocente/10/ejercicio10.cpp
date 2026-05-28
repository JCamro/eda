#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> cola;
    cola.push("apple");
    cola.push("banana");
    cola.push("cherry");
    cout << "Cola: ";
    queue<string> temp = cola;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    string front = cola.front();
    cola.pop();
    cout << "Elemento removido: " << front << endl;
    cout << "Cola después de remover: ";
    temp = cola;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    cola.push("date");
    string peeked = cola.front();
    cout << "Elemento mostrado: " << peeked << endl;
    cout << "Cola despues de la visualización: ";
    temp = cola;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    return 0;
}
