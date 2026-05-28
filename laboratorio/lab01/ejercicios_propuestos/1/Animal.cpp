#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
    string nombre;

public:
    Animal(string nombre)
    {
        this->nombre = nombre;
    }

    virtual void hacerSonido() {
        cout << "Sonido de Animal" << endl;
    }
};