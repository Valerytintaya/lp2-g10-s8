#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string n, double p, int c) : nombre(n), precio(p), cantidad(c) {}

    void setPrecio(double p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
};
