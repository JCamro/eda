#include <iostream>
#include <string>

using namespace std;

// Clase Base
class Bicicleta {
public:
    int gear;
    int speed;

    //Constructor
    Bicicleta(int gear, int speed) {
        this ->gear = gear;
        this ->speed = speed;
    }

    void aplicarFreno(int descuento) { speed -= descuento; }
    void acerlerar(int incremento) { speed += incremento; }

    // Metodo virtual para poder sobrescribir

    virtual string toString() {
        return "\nNumero de llantas: " + to_string(gear) + "\nla velocidad de la bicicleta es: " + 
        to_string(speed);
    }
};

// Clase derivada
class MountainBike : public Bicicleta {
public:
    int seatHeight;
 
    MountainBike(int gear, int speed, int startHeight)
        : Bicicleta(gear, speed) {
        seatHeight = startHeight;
    }
 
    void setHeight(int newValue) { seatHeight = newValue; }
 
    // Sobrescritura del método
    string toString() override {
        return Bicicleta::toString() +
               "\nAltura del asiento es: " + to_string(seatHeight);
    }
};
 
int main() {
    MountainBike mb(3, 100, 25);
    cout << mb.toString() << endl;

    mb.acerlerar(100);
    cout << mb.toString() << endl;
    
    mb.acerlerar(1000);
    cout << mb.toString() << endl;
    
    return 0;
}
