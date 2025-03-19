#include "Producto.h"

Producto::Producto(std::string nombre, double precio, int cantidad)
    : nombre(nombre), precio(precio), cantidadEnInventario(cantidad) {}

std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getCantidadEnInventario() const {
    return cantidadEnInventario;
}

void Producto::setCantidadEnInventario(int cantidad) {
    cantidadEnInventario = cantidad;
}
