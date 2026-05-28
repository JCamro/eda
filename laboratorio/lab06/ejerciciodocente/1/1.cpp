#include <iostream>

using namespace std;

class ArbolBinarioOrdenado {
private:

    // Clase Nodo
    class Nodo {
    public:
        int info;
        Nodo* izq;
        Nodo* der;

        Nodo(int valor) {
            info = valor;
            izq = nullptr;
            der = nullptr;
        }
    };

    Nodo* raiz;

    // Recorrido Preorden
    void imprimirPre(Nodo* reco) {
        if (reco != nullptr) {
            cout << reco->info << " ";
            imprimirPre(reco->izq);
            imprimirPre(reco->der);
        }
    }

    // Recorrido Inorden
    void imprimirEntre(Nodo* reco) {
        if (reco != nullptr) {
            imprimirEntre(reco->izq);
            cout << reco->info << " ";
            imprimirEntre(reco->der)
        }
    }

    // Recorrido Postorden
    void imprimirPost(Nodo* reco) {
        if (reco != nullptr) {
            imprimirPost(reco->izq);
            imprimirPost(reco->der);
            cout << reco->info << " ";
        }
    }

public:

    // Constructor
    ArbolBinarioOrdenado() {
        raiz = nullptr;
    }

    // Método insertar
    void insertar(int info) {

        Nodo* nuevo = new Nodo(info);

        if (raiz == nullptr) {
            raiz = nuevo;
        }
        else {
            Nodo* anterior = nullptr;
            Nodo* reco = raiz;

            while (reco != nullptr) {
                anterior = reco;

                if (info < reco->info)
                    reco = reco->izq;
                else
                    reco = reco->der;
            }

            if (info < anterior->info)
                anterior->izq = nuevo;
            else
                anterior->der = nuevo;
        }
    }

    // Método público Preorden
    void imprimirPre() {
        imprimirPre(raiz);
        cout << endl;
    }

    // Método público Inorden
    void imprimirEntre() {
        imprimirEntre(raiz);
        cout << endl;
    }

    // Método público Postorden
    void imprimirPost() {
        imprimirPost(raiz);
        cout << endl;
    }
};

// Función principal
int main() {

    ArbolBinarioOrdenado abo;

    abo.insertar(100);
    abo.insertar(50);
    abo.insertar(25);
    abo.insertar(75);
    abo.insertar(150);

    cout << "Impresion preorden: " << endl;
    abo.imprimirPre();

    cout << "Impresion entreorden (inorden): " << endl;
    abo.imprimirEntre();

    cout << "Impresion postorden: " << endl;
    abo.imprimirPost();

    return 0;
}
