#include <iostream>
#include <stdexcept> 
using namespace std;

// Función que divide dos enteros y lanza excepción si el divisor es cero
double divide(int numerador, int denominador) {
    if (denominador == 0) {
        throw runtime_error("Error: No se puede dividir por cero.");
    }
    return (numerador) / denominador;
}

int main() {
    int a, b;
    try {
        a = 10;
        b = 2;
        double n= divide(a, b);
        cout << "Resultado de " << a << " / " << b << " = " << n << endl;

    } catch (const runtime_error& e) {
        cerr << "[Excepción]: " << e.what() << endl;
    }

    // Caso 2: División por cero
    try {
        a = 5;
        b = 0;
        double n= divide(a, b);
        cout << "Resultado de " << a << " / " << b << " = " << n << endl;
    } catch (const runtime_error& e) {
        cerr << "[Excepción]: " << e.what() << endl;
    }

    // Caso 3: Otro ejemplo válido
    try {
        a = 20;
        b = 3;
        double n= divide(a, b);
        cout << "Resultado de " << a << " / " << b << " = " << n << endl;
    } catch (const runtime_error& e) {
        cerr << "[Excepción]: " << e.what() << endl;
    }

    return 0;
}
