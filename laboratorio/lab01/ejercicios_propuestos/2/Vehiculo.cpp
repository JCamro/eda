#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
private:
    string marca;
    string modelo;
public: 
    Vehiculo(string marca, string modelo) : marca(marca), modelo(modelo) {}

    virtual void iniciar() {
        cout << "El vehiculo esta en marcha!" << endl;
    }

    virtual void detener() {
        cout << "El vehiculo se ha detenido!" << endl;
    }
};
