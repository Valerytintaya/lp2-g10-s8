#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <string.h>
using namespace std;

// Clase Producto
class Producto {
public:
    char nombre[30];
    float precio;
    int cantidad;

    Producto() {}
    Producto(string nom, float pre, int cant) {
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

class Inventario {
private:
    string archivoBin = "productos.dat";
    string archivoIndice = "indice.txt";
    map<string, int> indice;  

    void cargarIndice() {
        indice.clear();
        ifstream file(archivoIndice);
        string nombre;
        int pos;

        while (file >> nombre >> pos) {
            indice[nombre] = pos;
        }

        file.close();
    }

    void guardarIndice() {
        ofstream file(archivoIndice);
        for (const auto& par : indice) {
            file << par.first << " " << par.second << endl;
        }
        file.close();
    }

public:
    Inventario() {
        cargarIndice();
    }

    void agregarProducto(const Producto& p) {
        fstream binario(archivoBin, ios::out | ios::binary | ios::app);
        if (!binario) {
            cerr << "No se pudo abrir el archivo binario.\n";
            return;
        }

        int posicion = indice.size();  // registro N
        binario.write(reinterpret_cast<const char*>(&p), sizeof(Producto));
        binario.close();

        indice[p.nombre] = posicion;
        guardarIndice();

        cout << "Producto agregado con acceso aleatorio.\n";
    }

    void buscarProductoPorNombre(const string& nombre) {
        if (indice.find(nombre) == indice.end()) {
            cout << "Producto no encontrado.\n";
            return;
        }

        int pos = indice[nombre];
        ifstream binario(archivoBin, ios::in | ios::binary);
        if (!binario) {
            cerr << "Error al abrir el archivo binario.\n";
            return;
        }

        Producto p;
        binario.seekg(pos * sizeof(Producto), ios::beg);
        binario.read(reinterpret_cast<char*>(&p), sizeof(Producto));
        binario.close();

        cout << "Producto encontrado:\n";
        p.mostrar();
    }
    void generarInforme() {
        ifstream binario(archivoBin, ios::in | ios::binary);
        if (!binario) {
            cerr << "Error al abrir productos.dat\n";
            return;
        }

        Producto p;
        cout << "--- INFORME COMPLETO ---\n";
        while (binario.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
            p.mostrar();
        }
        cout << "-------------------------\n";
        binario.close();
    }
};
