#include <iostream>
using namespace std;

// Clase Stack (Pila)
class Stack {
    int top, cap;
    int* a;
public:
    // Constructor
    Stack(int cap) {
        this->cap = cap;
        top = -1;
        a = new int[cap];
    }
    // Método push
    bool push(int x) {
        if (top >= cap - 1) {
            cout << "Desbordamiento de pila" << endl;
            return false;
        }
        a[++top] = x;
        return true;
    }
    // Método pop
    int pop() {
        if (top < 0) {
            cout << "Desbordamiento por debajo de la pila" << endl;
            return 0;
        }
        return a[top--];
    }
    // Método peek
    int peek() {
        if (top < 0) {
            cout << "La pila está vacía" << endl;
            return 0;
        }
        return a[top];
    }
    // Verificar si la pila está vacía
    bool isEmpty() {
        return top < 0;
    }
    // Destructor para liberar memoria
    ~Stack() {
        delete[] a;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " sacado de la pila" << endl;
    cout << "El elemento en la cima es: " << s.peek() << endl;
    cout << "Elementos presentes en la pila: ";
    while (!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}
