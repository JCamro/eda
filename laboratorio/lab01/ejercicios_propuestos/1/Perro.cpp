#include <iostream>
#include <string>

using namespace std;

#include "Animal.cpp"

class Perro : public Animal {
public:
    Perro(string nombre) : Animal(nombre) {}

    void hacerSonido() override {
        cout << "Guau! Guau!" << endl;
    }
};
