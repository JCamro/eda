#include <iostream>
#include <string>

using namespace std;

int main() {
    //Creacion de puntero arreglo de longitud 4
    string *arreglo = new string[4]{"Hola", "Amigo", "Soy", "Josue"};

    //Se recorre el arreglo
    for(int i = 0; i < arreglo->length(); i++) {
        cout << arreglo[i] << endl;
    }
    
    //Se elimina de memoria el arreglo
    delete[] arreglo;
    return 0;
}