#include <iostream>
#include <string>
using namespace std;

// A) Crear una clase Producto
class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string n, double p, int c) : nombre(n), precio(p), cantidad(c) {}

    // 2A) Métodos para establecer precio y cantidad de un producto
    void setPrecio(double p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    // Métodos para obtener los valores
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
};
