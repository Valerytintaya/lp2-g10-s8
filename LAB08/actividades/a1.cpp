#include <iostream>
#include <cmath>
using namespace std;

// Clase abstracta base
class Figura {
public:
    virtual double calcularArea() = 0; // Método puramente virtual
    virtual ~Figura() {} // Destructor virtual
};

// Clases derivadas

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return M_PI * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return (base * altura) / 2;
    }
};

class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() override {
        return lado * lado;
    }
};

class Pentagono : public Figura {
private:
    double lado, apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {}
    double calcularArea() override {
        return (5 * lado * apotema) / 2;
    }
};

// Función principal
int main() {
    Figura* figura = nullptr;
    int opcion;
    cout << "Seleccione una figura para calcular su área:\n";
    cout << "1. Círculo\n";
    cout << "2. Rectángulo\n";
    cout << "3. Triángulo\n";
    cout << "4. Cuadrado\n";
    cout << "5. Pentágono\n";
    cout << "Opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio: ";
            cin >> radio;
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ingrese la altura: ";
            cin >> altura;
            figura = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double base, altura;
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ingrese la altura: ";
            cin >> altura;
            figura = new Triangulo(base, altura);
            break;
        }
        case 4: {
            double lado;
            cout << "Ingrese el lado: ";
            cin >> lado;
            figura = new Cuadrado(lado);
            break;
        }
        case 5: {
            double lado, apotema;
            cout << "Ingrese el lado: ";
            cin >> lado;
            cout << "Ingrese el apotema: ";
            cin >> apotema;
            figura = new Pentagono(lado, apotema);
            break;
        }
        default:
            cout << "Opción inválida.\n";
            return 1;
    }

    if (figura) {
        cout << "El área de la figura es: " << figura->calcularArea() << endl;
        delete figura;
    }
    return 0;
}
