#include <iostream>
using namespace std;

class principal {
public:
    void myPublicMethod() {
        cout << "Metodos publicos deben ser llamados creando objetos" << endl;
    }

    static void myStaticMethod() {
        cout << "Metodos estaticos pueden ser llamados sin crear objetos" << endl;
    }
};
