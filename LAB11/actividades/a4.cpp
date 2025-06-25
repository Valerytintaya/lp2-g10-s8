#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstring>
using namespace std;

class ProductoNoEncontrado : public exception {
    string mensaje;
public:
    ProductoNoEncontrado(string nombre) {
        mensaje = "Producto '" + nombre + "' no encontrado.";
    }
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class StockInsuficiente : public exception {
public:
    const char* what() const noexcept override {
        return "Stock insuficiente para completar la venta.";
    }
};

class Producto {
public:
    char nombre[30];
    float precio;
    int cantidad;

    Producto() {}
    Producto(string nom, float pre, int cant) {
        if (pre < 0 || cant < 0 || nom.empty())
            throw invalid_argument("Datos inválidos en creación de producto.");

        strncpy(nombre, nom.c_str(), sizeof(nombre));
        nombre[sizeof(nombre) - 1] = '\0';
        precio = pre;
        cantidad = cant;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre
             << ", Precio: " << precio
             << ", Cantidad: " << cantidad << endl;
    }
};

// Inventario con manejo de excepciones
class InventarioSeguro {
private:
    string archivoBin = "productos.dat";
    string archivoIndice = "indice.txt";
    map<string, int> indice;

    void cargarIndice() {
        ifstream file(archivoIndice);
        if (!file)
            throw runtime_error("No se pudo abrir el archivo de índice.");

        string nombre;
        int pos;
        while (file >> nombre >> pos)
            indice[nombre] = pos;
        file.close();
    }

    void guardarIndice() {
        ofstream file(archivoIndice);
        for (const auto& p : indice)
            file << p.first << " " << p.second << endl;
        file.close();
    }

public:
    InventarioSeguro() {
        try {
            cargarIndice();
        } catch (const exception& e) {
            cerr << "[ERROR]: " << e.what() << endl;
        }
    }

    void agregarProducto(const Producto& p) {
        try {
            fstream binario(archivoBin, ios::app | ios::binary);
            if (!binario)
                throw runtime_error("Error al abrir archivo binario para escritura.");

            int posicion = indice.size();
            binario.write(reinterpret_cast<const char*>(&p), sizeof(Producto));
            binario.close();

            indice[p.nombre] = posicion;
            guardarIndice();
            cout << "Producto agregado con éxito.\n";

        } catch (const exception& e) {
            cerr << "[ERROR]: " << e.what() << endl;
        }
    }

    void buscarProducto(const string& nombre) {
        try {
            if (indice.find(nombre) == indice.end())
                throw ProductoNoEncontrado(nombre);

            ifstream binario(archivoBin, ios::binary);
            if (!binario)
                throw runtime_error("No se pudo abrir el archivo binario.");

            Producto p;
            binario.seekg(indice[nombre] * sizeof(Producto));
            binario.read(reinterpret_cast<char*>(&p), sizeof(Producto));
            binario.close();

            p.mostrar();

        } catch (const exception& e) {
            cerr << "[ERROR]: " << e.what() << endl;
        }
    }

    void venderProducto(const string& nombre, int cantidadVendida) {
        try {
            if (cantidadVendida <= 0)
                throw invalid_argument("Cantidad vendida debe ser positiva.");

            if (indice.find(nombre) == indice.end())
                throw ProductoNoEncontrado(nombre);

            fstream binario(archivoBin, ios::in | ios::out | ios::binary);
            if (!binario)
                throw runtime_error("No se pudo abrir archivo binario.");

            Producto p;
            int pos = indice[nombre];
            binario.seekg(pos * sizeof(Producto));
            binario.read(reinterpret_cast<char*>(&p), sizeof(Producto));

            if (p.cantidad < cantidadVendida)
                throw StockInsuficiente();

            p.cantidad -= cantidadVendida;

            binario.seekp(pos * sizeof(Producto));
            binario.write(reinterpret_cast<char*>(&p), sizeof(Producto));
            binario.close();

            cout << "Venta realizada con éxito.\n";

        } catch (const exception& e) {
            cerr << "[ERROR]: " << e.what() << endl;
        }
    }
};
