#include <iostream>
#include <string>

using namespace std;

class Auto {
private:
    string modelo;
    int anio;

public:
    //Constructor por defecto
    Auto() {
        modelo = "Desconocido";
        anio = 0;
    }

    Auto(string modelo, int anio)
        : modelo(modelo), anio(anio) {}

    void mostrarModelo() {
        cout <<"Modelo: "<<modelo << endl;
    }
    
    void mostrarAnio() {
        cout <<"Anio: "<< anio << endl;
    }
};