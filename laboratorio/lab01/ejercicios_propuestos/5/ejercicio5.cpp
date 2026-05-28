#include <iostream>
#include <string>

namespace Matematicas {
    void mostrar() {
        double pi = 3.14159;
        std::cout << "[Matematicas] El valor aproximado de PI es: " << pi << std::endl;
    }
}

namespace Texto {
    void mostrar() {
        std::string mensaje = "Hola, este es un mensaje de texto.";
        std::cout << "[Texto] Contenido del mensaje: " << mensaje << std::endl;
    }
}

int main() {
    
    Matematicas::mostrar();

    Texto::mostrar();

    return 0;
}