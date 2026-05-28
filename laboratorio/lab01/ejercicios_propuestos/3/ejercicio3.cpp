#include <iostream>
#include <string>

using namespace std;

#include "Auto.cpp"

int main() {

    Auto miCarro1;
    Auto miCarro2("Jimmy", 2026);

    miCarro1.mostrarAnio();
    miCarro1.mostrarModelo();
    
    miCarro2.mostrarAnio();
    miCarro2.mostrarModelo();

    return 0;
}