#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidadEnInventario;

public:
    Producto(string nom, double pre, int cant);
    
    string getNombre();
    double getPrecio();
    int getCantidadEnInventario();

    void setNombre(string nom);
    void setPrecio(double pre);
    void setCantidadEnInventario(int cant);
};

#endif
