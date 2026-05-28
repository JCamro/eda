#include <iostream>
#include <string>

using namespace std;

#include "DiaDeSemana.cpp"

static void diaLaborable(DiaDeSemana dia) {
    if (dia == SABADO || dia == DOMINGO){
        cout << "El dia no es laborable" << endl;
    }
    else {
        cout << "El dia es laborable" << endl;
    }
}

int main() {
    DiaDeSemana dia1(LUNES);
    DiaDeSemana dia2(DOMINGO);

    diaLaborable(dia1);
    diaLaborable(dia2);

    return 0;
}