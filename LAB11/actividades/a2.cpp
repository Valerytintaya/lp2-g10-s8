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
    Producto(string nombre, float precio, int cantidad)
        : nombre(nombre), precio(precio), cantidad(cantidad) {}

    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setPrecio(float p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << ", Precio: " << precio
             << ", Cantidad: " << cantidad << endl;
    }

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

    vector<Producto> cargarProductos() {
        vector<Producto> productos;
        ifstream file(archivo);
        string linea;

        while (getline(file, linea)) {
            productos.push_back(Producto::desdeTexto(linea));
        }

        file.close();
        return productos;
    }

    void guardarProductos(const vector<Producto>& productos) {
        ofstream file(archivo, ios::trunc); 
        for (const auto& p : productos) {
            file << p.aTexto() << endl;
        }
        file.close();
    }

public:
    void agregarProducto(const Producto& p) {
        ofstream file(archivo, ios::app);
        if (file.is_open()) {
            file << p.aTexto() << endl;
            file.close();
            cout << "Producto agregado correctamente.\n";
        } else {
            cerr << "Error: No se pudo abrir el archivo para escritura.\n";
        }
    }

    void actualizarProducto(const string& nombre, float nuevoPrecio, int nuevaCantidad) {
        vector<Producto> productos = cargarProductos();
        bool encontrado = false;

        for (auto& p : productos) {
            if (p.getNombre() == nombre) {
                p.setPrecio(nuevoPrecio);
                p.setCantidad(nuevaCantidad);
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            guardarProductos(productos);
            cout << "Producto actualizado exitosamente.\n";
        } else {
            cout << "Producto no encontrado.\n";
        }
    }

    void venderProducto(const string& nombre, int cantidadVendida) {
        vector<Producto> productos = cargarProductos();
        bool encontrado = false;

        for (auto& p : productos) {
            if (p.getNombre() == nombre) {
                if (p.getCantidad() >= cantidadVendida) {
                    p.setCantidad(p.getCantidad() - cantidadVendida);
                    encontrado = true;
                } else {
                    cout << "Error: Stock insuficiente.\n";
                    return;
                }
                break;
            }
        }

        if (encontrado) {
            guardarProductos(productos);
            cout << "Venta registrada exitosamente.\n";
        } else {
            cout << "Producto no encontrado.\n";
        }
    }

    void generarInforme() {
        vector<Producto> productos = cargarProductos();
        cout << "--- INFORME DE INVENTARIO ---\n";
        for (const auto& p : productos) {
            p.mostrar();
        }
        cout << "-----------------------------\n";
    }
};

int main() {
    Inventario inventario;

    // Pruebas:
    inventario.agregarProducto(Producto("Laptop", 2500.50, 10));
    inventario.agregarProducto(Producto("Mouse", 45.99, 50));

    inventario.actualizarProducto("Mouse", 49.99, 40);
    inventario.venderProducto("Laptop", 2);

    inventario.generarInforme();

    return 0;
}
