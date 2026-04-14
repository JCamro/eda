#include <iostream>
using namespace std;

class Nodo
{
private:
    int dato;
    Nodo* next;

public:
    //Constructor
    Nodo(int dato) 
    {
        this->dato = dato;
        //NEXT REPRESENTA AL NODO SIGUIENTE (ANTIGUO NODO CIMA)
        this->next = nullptr;
    }

    //getters
    int getDato() 
    {
        return this->dato;
    }

    Nodo* getNext() 
    {
        return this->next;
    }

    //setters
    void setDato(int dato) 
    {
        this->dato = dato;
    }

    void setNext(Nodo* next) 
    {
        this->next = next;
    }
    
};

class pila
{
private:
    Nodo* cima;
    int size;

public:
    
    //Constructor
    pila() {
        this->cima = nullptr;
        this->size = 0;
    }
    
    //push
    void push (int dato) 
    {
        //Se crea el nuevo nodo
        Nodo* nuevo_nodo = new Nodo(dato);
        
        //Nodo cima actual apunta al nuevo nodo cima
        nuevo_nodo->setNext(this->cima);

        //Nuevo dato se convierte en el nuevo nodo cima
        this->cima = nuevo_nodo;

        //Aumentamos la cantidad de elementos en la pila
        this->size++;
    }    

    //pop 
    int pop() {

        //Verificamos si la pila esta vacia

        if (this->cima == nullptr) 
        {
            cout << "La pila está vacía" << endl;
            return -1;
        }
        
        //DEBEMOS PRIORIZAR NO TENER MEMORY LEAKS

        //Puntero a nodo cima
        Nodo* nodo_cima = this->cima;

        //Obtenemos el dato del nodo cima
        int dato = nodo_cima->getDato();
        
        //Hacemos el cambio que nodo cima sea el anterior nodo cima
        this->cima = this->cima->getNext();

        //Borramos el nodo cima de la memoria
        delete nodo_cima;

        //Reducimos la cantidad de elementos en la pila
        this->size--;

        //Retornamos el dato que se elimino
        return dato;
    }
};

