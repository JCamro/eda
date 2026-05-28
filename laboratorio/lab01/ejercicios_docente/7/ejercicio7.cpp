#include <iostream>
using namespace std;
// Incluimos la clase
#include "principal.cpp"

int main() {
    principal myObj;

    myObj.x = 25; // x ahora es 25

    cout << myObj.x << endl;

    return 0;
}
