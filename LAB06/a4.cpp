#include <iostream>
using namespace std;

// Clase que representa un vector en 2D
class Vector2D {
private:
    double x, y;  // Componentes del vector

public:
    // Constructor
    Vector2D(double x = 0.0, double y = 0.0) {
        this->x = x;
        this->y = y;
    }
    void mostrar() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    // Sobrecarga del operador +
    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }
    // Sobrecarga del operador -
    Vector2D operator-(const Vector2D& otro) const {
        return Vector2D(x - otro.x, y - otro.y);
    }
};

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.5, 2.5);
    cout << "Vector 1: "; v1.mostrar();
    cout << "Vector 2: "; v2.mostrar();
    Vector2D suma = v1 + v2;
    cout << "\nSuma: "; suma.mostrar();
    Vector2D resta = v1 - v2;
    cout << "Resta: "; resta.mostrar();
    return 0;
}
