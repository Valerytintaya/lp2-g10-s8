#include <iostream>
#include <cmath>
using namespace std;

// Clase completamente abstracta (interfaz)
class Forma {
public:
    virtual double calcularPerimetro() = 0; // Método puramente virtual
    virtual ~Forma() {}
};

// Clases derivadas

class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularPerimetro() override {
        return 2 * M_PI * radio;
    }
};

class Rectangulo : public Forma {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};

class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}
    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};

int main() {
    Forma* forma = nullptr;
    int opcion;
    cout << "Seleccione una forma para calcular su perímetro:\n";
    cout << "1. Círculo\n";
    cout << "2. Rectángulo\n";
    cout << "3. Triángulo\n";
    cout << "Opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio del círculo: ";
            cin >> radio;
            forma = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese la base del rectángulo: ";
            cin >> base;
            cout << "Ingrese la altura del rectángulo: ";
            cin >> altura;
            forma = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double l1, l2, l3;
            cout << "Ingrese el lado 1 del triángulo: ";
            cin >> l1;
            cout << "Ingrese el lado 2 del triángulo: ";
            cin >> l2;
            cout << "Ingrese el lado 3 del triángulo: ";
            cin >> l3;
            forma = new Triangulo(l1, l2, l3);
            break;
        }
        default:
            cout << "Opción inválida.\n";
            return 1;
    }
    if (forma) {
        cout << "El perímetro de la forma seleccionada es: " << forma->calcularPerimetro() << endl;
        delete forma;
    }
    return 0;
}
