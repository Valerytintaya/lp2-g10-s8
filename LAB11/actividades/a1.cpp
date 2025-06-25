#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Producto {
private:
    string nombre;
    float precio;
    int cantidad;

public:
    Producto() {}
    Producto(string nombre, float precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }

    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setNombre(string n) { nombre = n; }
    void setPrecio(float p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << ", Precio: " << precio
             << ", Cantidad: " << cantidad << endl;
    }

    // Guardar en archivo (formato CSV)
    string aTexto() const {
        return nombre + "," + to_string(precio) + "," + to_string(cantidad);
    }

    static Producto desdeTexto(const string& linea) {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);

        string nombre = linea.substr(0, pos1);
        float precio = stof(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        int cantidad = stoi(linea.substr(pos2 + 1));

        return Producto(nombre, precio, cantidad);
    }
};


class Inventario {
private:
    string archivo = "inventario.txt";

public:
    void agregarProducto(const Producto& p);

    void actualizarProducto(const string& nombre, float nuevoPrecio, int nuevaCantidad);

    void venderProducto(const string& nombre, int cantidadVendida);

    void generarInforme();

    Producto buscarProducto(const string& nombre);
};
