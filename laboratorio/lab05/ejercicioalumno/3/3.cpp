#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool equilibrado(string expresion)
{
    stack<char> miStack;

    for (char i : expresion)
    {
        if (i == '(' || i == '[' || i == '{')
        {
            miStack.push(i);
        }
        else if (i == ')' || i == ']' || i == '}')
        {
            if (miStack.empty())
            {
                return false;
            }

            char tope = miStack.top();

            if ((i == ')' && tope == '(') ||
                (i == ']' && tope == '[') ||
                (i == '}' && tope == '{'))
            {
                miStack.pop(); // Coinciden, así que eliminamos el de apertura de la pila
            }
            else
            {
                return false; // No coinciden (ej. se intenta cerrar un '[' con un ')')
            }
        }
    }
    // Al terminar, si la pila quedó completamente vacía, todo se cerró correctamente
    return miStack.empty();
}

int main() {
    // Casos de prueba
    string exp1 = "{[()]}";
    string exp2 = "{[(])}";
    string exp3 = "(((())))";
    string exp4 = "([)]";

    cout << "--- Verificador de Corchetes Equilibrados ---" << endl;
    
    cout << exp1 << " -> " << (equilibrado(exp1) ? "Equilibrado" : "No Equilibrado") << endl;
    cout << exp2 << " -> " << (equilibrado(exp2) ? "Equilibrado" : "No Equilibrado") << endl;
    cout << exp3 << " -> " << (equilibrado(exp3) ? "Equilibrado" : "No Equilibrado") << endl;
    cout << exp4 << " -> " << (equilibrado(exp4) ? "Equilibrado" : "No Equilibrado") << endl;

    return 0;
}