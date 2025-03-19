#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto {
private:
    std::string nombre;
    double precio;
    int cantidadEnInventario;

public:
    Producto(std::string nombre, double precio, int cantidad);
    std::string getNombre() const;
    double getPrecio() const;
    int getCantidadEnInventario() const;
    void setCantidadEnInventario(int cantidad);
};

#endif
