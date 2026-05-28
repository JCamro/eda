#include <iostream>
using namespace std;

class Car {
public:
    void fullThrottle() {
        cout << "El auto ira tan rpido como puede!" << endl;
    }

    void speed(int maxSpeed) {
        cout << "La maxima velocidad es: " << maxSpeed << endl;
    }
};
