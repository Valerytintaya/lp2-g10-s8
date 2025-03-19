#include "Producto.h"

Producto::Producto(string nom, double pre, int cant) {
    nombre = nom;
    precio = pre;
    cantidadEnInventario = cant;
}

string Producto::getNombre() {
    return nombre;
}

double Producto::getPrecio() {
    return precio;
}

int Producto::getCantidadEnInventario() {
    return cantidadEnInventario;
}

void Producto::setNombre(string nom) {
    nombre = nom;
}

void Producto::setPrecio(double pre) {
    precio = pre;
}

void Producto::setCantidadEnInventario(int cant) {
    cantidadEnInventario = cant;
}
