#include <iostream>
using namespace std;

template<typename T>
class DobleLinkedList {
public:

    // Implementacion de Nodo
    class Node {
    public:
        T data;
        Node* next;
        Node* post;

        Node(T data) {
            this->data = data;
            this->next = nullptr;
            this->post = nullptr;
        }
    };

    // Nodo cabeza de DLL 
    Node* head;

    // Constructor de DobleLinkedList
    DobleLinkedList() {
        head = nullptr;
    }

    void insert(T data) {
        Node* nuevo_nodo = new Node(data);

        if (head == nullptr) {
            head = nuevo_nodo;
            return;
        }

        head->next = nuevo_nodo;
        nuevo_nodo->post = head;
        head = nuevo_nodo;
    }

    void printList() {
        Node* nodoActual = head;

        while (nodoActual != nullptr) {
            cout << nodoActual->data << endl;
            nodoActual = nodoActual->post;
        }
    }
};

int main() {
    DobleLinkedList<int> lista;

    lista.insert(1);
    lista.insert(2);
    lista.insert(3);
    lista.insert(4);
    lista.insert(5);
    lista.insert(6);
    lista.insert(7);
    lista.insert(8);
    lista.insert(9);
    lista.insert(10);

    lista.printList();
}