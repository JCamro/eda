#include <iostream>
using namespace std;

// Definición de la clase Nodo
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Definición de la clase Cola
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }
    // Verificar si la cola está vacía
    bool isEmpty() {
        return front == nullptr;
    }
    // Insertar elementos en la cola
    void enqueue(int new_data) {
        Node* new_node = new Node(new_data);
        if (isEmpty()) {
            front = rear = new_node;
            printQueue();
            return;
        }
        rear->next = new_node;
        rear = new_node;
        printQueue();
    }
    // Eliminar elementos de la cola
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        printQueue();
    }
    // Mostrar la cola actual
    void printQueue() {
        if (isEmpty()) {
            cout << "Cola esta vacia" << endl;
            return;
        }
        Node* temp = front;
        cout << "Cola actual: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    // Poner elementos en cola
    q.enqueue(10);
    q.enqueue(20);
    // Sacar elementos de la cola
    q.dequeue();
    q.dequeue();
    // Poner más elementos en la cola
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    // Sacar un elemento de la cola
    q.dequeue();
    return 0;
}
