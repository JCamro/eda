/*
    CONCEPTO DE COLA (QUEUE)
    - Es una estructura de datos lineal que sigue el principio FIFO (First In, First Out).
    - Se pueden realizar dos operaciones principales: enqueue (agregar un elemento al final de la cola) y dequeue (eliminar el elemento al frente de la cola).
    - La cola se puede implementar utilizando arrays o listas enlazadas.
*/

class Nodo {
private:
    int dato;
    //ESTE NODO APUNTA AL SIGUIENTE (NUEVO NODO FONDO)
    Nodo* siguiente;

public:
    //Constructor
    Nodo(int dato) 
    {
        this->dato = dato;
        this->siguiente = nullptr;
    }

    //Getters
    int getDato() 
    {
        return this->dato;
    }

    Nodo* getSiguiente() 
    {
        return this->siguiente;
    }


    //Setters
    void setSiguiente(Nodo* siguiente) 
    {
        this->siguiente = siguiente;
    }
};



class Queue {

private:
    Nodo* frente;
    Nodo* fondo;
    int size;

public:
    Queue() 
    {
        this->frente = nullptr;
        this->fondo = nullptr;
        this->size = 0;
    }


    // Enqueue: Agregar un elemento al final de la cola
    void enqueue(int dato)
    {   
        //Se crea el nuevo nodo
        Nodo* nuevo_nodo = new Nodo(dato);

        //Se verifica si la cola está vacía
        if (frente == nullptr)
        {
            frente = nuevo_nodo;
            fondo = nuevo_nodo;
        }
        else 
        {
            //El nodo fondo actual apunta al nuevo nodo ingresado
            fondo->setSiguiente(nuevo_nodo);

            //Se establece el nuevo nodo
            fondo = nuevo_nodo;
        }
        
    }

    int dequeue() 
    {
        //Se verifica si la cola está vacía
        if (frente == nullptr)
        {
            std::cout << "La cola está vacía. No se puede realizar dequeue." << std::endl;
            return -1; // Indicador de error
        }

        //Se crea un nodo temporal para almacenar el nodo que se va a eliminar (frente)
        Nodo* nodo_a_eliminar = frente;

        //Se almacena el dato a eliminar
        int dato = nodo_a_eliminar->getDato();

        //Se actualiza el frente (nodo que sigue al antiguo nodo frente) para que apunte al siguiente nodo
        frente = frente->getSiguiente();

        //Se elimina el nodo que se va a eliminar
        delete nodo_a_eliminar;

        return dato;
    }
};