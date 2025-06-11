#include <iostream>
using namespace std;

class Calculadora {
public:
    // Sumar dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // Sumar dos doubles
    double sumar(double a, double b) {
        return a + b;
    }

    // Sumar tres enteros
    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculadora calc;
    cout << "sumar(int, int): " << calc.sumar(5, 10) << endl;          
    cout << "sumar(double, double): " << calc.sumar(2.5, 3.7) << endl;  
    cout << "sumar(int, int, int): " << calc.sumar(1, 2, 3) << endl;    

    return 0;
}
