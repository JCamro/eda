#include <iostream>

using namespace std;

// Clase Nodo
class Nodo {
public:
    int data;
    Nodo* left;
    Nodo* right;

    // Constructor
    Nodo(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Clase Árbol Binario de Búsqueda
class ArbolBinarioBusqueda {

private:
    Nodo* root;

public:

    // Constructor
    ArbolBinarioBusqueda() {
        root = nullptr;
    }

    // Método para asignar la raíz
    void crearArbolEjemplo() {

        // Crear el BST:
        //        20
        //       /  \
        //      8   22
        //     / \
        //    4  12
        //       / \
        //      10 14

        root = new Nodo(20);

        root->left = new Nodo(8);
        root->right = new Nodo(22);

        root->left->left = new Nodo(4);
        root->left->right = new Nodo(12);

        root->left->right->left = new Nodo(10);
        root->left->right->right = new Nodo(14);
    }

    // Función de búsqueda iterativa
    bool buscar(int x) {

        Nodo* curr = root;

        while (curr != nullptr) {

            // Si el nodo actual contiene x
            if (curr->data == x)
                return true;

            // Buscar en el subárbol derecho
            else if (curr->data < x)
                curr = curr->right;

            // Buscar en el subárbol izquierdo
            else
                curr = curr->left;
        }

        // No encontrado
        return false;
    }
};

// Función principal
int main() {

    ArbolBinarioBusqueda abb;

    abb.crearArbolEjemplo();

    int x = 12;

    if (abb.buscar(x))
        cout << "El valor " << x << " SI existe en el arbol." << endl;
    else
        cout << "El valor " << x << " NO existe en el arbol." << endl;

    return 0;
}
