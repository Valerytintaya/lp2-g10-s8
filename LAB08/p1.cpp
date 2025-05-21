#include <iostream>
#include <cmath>
using namespace std;

// Clase abstracta
class Figura {
public:
    // Métodos puramente virtuales
    virtual void dibujar() = 0;
    virtual double calcularArea() = 0;

    virtual ~Figura() {} // Destructor virtual
};

// Clase Círculo
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    void dibujar()  override {
        cout << "Dibujando un círculo de radio " << radio << endl;
    }

    double calcularArea() override {
        return M_PI * radio * radio;
    }
};

// Clase Rectángulo
class Rectangulo : public Figura {
private:
    double base, altura;

public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    void dibujar()  override {
        cout << "Dibujando un rectángulo de base " << base << " y altura " << altura << endl;
    }

    double calcularArea() override {
        return base * altura;
    }
};

// Clase Triángulo
class Triangulo : public Figura {
private:
    double base, altura;

public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    void dibujar()  override {
        cout << "Dibujando un triángulo de base " << base << " y altura " << altura << endl;
    }

    double calcularArea()  override {
        return (base * altura) / 2.0;
    }
};

int main() {
    Figura* figuras[3];

    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 6.0);
    figuras[2] = new Triangulo(3.0, 5.0);

    for (int i = 0; i < 3; ++i) {
        figuras[i]->dibujar();
        cout << "Área: " << figuras[i]->calcularArea() << endl;
        cout << "------------------------" << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete figuras[i];
    }

    return 0;
}
