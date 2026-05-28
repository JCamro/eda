#include <iostream>
using namespace std;

template<typename T>
class CircularList {
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
    Node* tall;

    // Constructor de CircularList
    CircularList() {
        head = nullptr;
        tall = nullptr;
    }

    void insert(T data) {
        Node* nuevo_nodo = new Node(data);

        if (head == nullptr && tall == nullptr) {
            head = nuevo_nodo;
            return;

        }

        else if (tall == nullptr) {
            head->next = nuevo_nodo;
            head->post = nuevo_nodo;

            nuevo_nodo->next = head;
            nuevo_nodo->post = head;

            tall =  nuevo_nodo;

            return;
        }

        //Siguiente es el nuevo nodo
        tall->next = nuevo_nodo;

        //El nuevo nodo apunta a la cabeza
        nuevo_nodo->next = head;

        //El nuevo nodo apunta como anterior a la cola
        nuevo_nodo->post = tall;

        //El nuevo nodo pasa a ser la cola
        tall = nuevo_nodo;

    }

    void printList() {
        Node* nodoActual = head;
        
        do {
            cout << nodoActual->data << endl;
            nodoActual = nodoActual->next;
            
        } while (nodoActual != head);
    }
};


int main() {
    CircularList<int> lista;

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

    return 0;
}