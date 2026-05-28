#include <iostream>
#include <string>

using namespace std;

#include "Auto.cpp"

int main() {
    
    Auto miCoche("Susuki", "Jimmy");
    
    miCoche.iniciar();
    miCoche.detener();
    
    return 0;
}