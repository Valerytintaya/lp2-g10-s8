#include <iostream>
#include <string>
using namespace std;

class Tienda {
private:
    string nombre, direccion, tipoDeTienda;
    int stock;

public:
    // Constructor
    Tienda(string _nombre, string _direccion, string _tipoDeTienda, int _stock)
        : nombre(_nombre), direccion(_direccion), tipoDeTienda(_tipoDeTienda), stock(_stock) {}

    void venderProducto(int cantidad) {
        if (stock >= cantidad) {
            stock -= cantidad;
            cout << "Se vendieron " << cantidad << " productos en " << nombre << "." << endl;
        } else {
            cout << "No hay suficiente stock en " << nombre << ". Stock disponible: " << stock << "." << endl;
        }
    }

    void agregarProducto(int cantidad) {
        stock += cantidad;
        cout << " Se agregaron " << cantidad << " productos a " << nombre << ". Stock actual: " << stock << "." << endl;
    }

    void mostrar_info() {
        cout << "Nombre: " << nombre << " | Dirección: " << direccion << " | Tipo: " << tipoDeTienda << endl;
        cout << "Stock disponible: " << stock << endl;
    }

    string getNombre() { return nombre; }
};

int main() {
    Tienda tiendas[2] = {
        Tienda("Moda Express", "Av. Principal 123", "Ropa", 50),
        Tienda("Tech Center", "Calle Electrónica 45", "Electrónicos", 30)
    };

    // Mostrar información de las tiendas
    for (int i = 0; i < 2; i++) {
        tiendas[i].mostrar_info();
        cout << "-------------------------" << endl;
    }

    int cantidad;

    // Vender productos
    for (int i = 0; i < 2; i++) {
        cout << " ¿Cuántos productos desea vender en " << tiendas[i].getNombre() << "? ";
        cin >> cantidad;
        tiendas[i].venderProducto(cantidad);
        cout << "-------------------------" << endl;
    }

    // Agregar productos
    for (int i = 0; i < 2; i++) {
        cout << " ¿Cuántos productos desea agregar a " << tiendas[i].getNombre() << "? ";
        cin >> cantidad;
        tiendas[i].agregarProducto(cantidad);
        cout << "-------------------------" << endl;
    }
    return 0;
}

