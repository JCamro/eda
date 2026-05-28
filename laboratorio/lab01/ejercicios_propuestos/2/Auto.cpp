#include <iostream>
#include <string>

using namespace std;

#include "Vehiculo.cpp"

class Auto : public Vehiculo {

public:
    Auto(string marca, string modelo)
        : Vehiculo(marca, modelo)
    {

    }
    
    void iniciar() override {
        cout << "El Auto esta en marcha!" << endl;
    }
    
    void detener() override {
        cout << "El Auto se ha detenido!" << endl;
    }
};