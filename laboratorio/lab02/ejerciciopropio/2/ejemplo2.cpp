#include <iostream>
#include <type_traits>

// Plantilla genérica para cualquier tipo
template <typename T>
void imprimirArreglo(T arr[], int size) {
    std::cout << "Arreglo generico: ";
    for (int i = 0; i < size; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Especialización: Restringir para que solo funcione con arreglos de 'char'
template <>
void imprimirArreglo<char>(char arr[], int size) {
    std::cout << "Arreglo de caracteres (especializado): ";
    for (int i = 0; i < size; ++i) std::cout << "[" << arr[i] << "]";
    std::cout << std::endl;
}

int main() {
    int nums[] = {1, 2, 3};
    char letras[] = {'A', 'B', 'C'};

    imprimirArreglo(nums, 3);   // Usa la versión genérica
    imprimirArreglo(letras, 3); // Usa la versión especializada para char

    return 0;
}