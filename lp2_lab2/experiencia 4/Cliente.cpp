#include <iostream>
#include <vector>
using namespace std;

#include "Producto.cpp"

// 1) Crear una clase Cliente
class Cliente {
private:
    string nombre;
    vector<Producto> compras; // 1B) Lista de compras del cliente

public:
    Cliente(string n) : nombre(n) {}

    // 1B) Método para agregar productos a la lista de compras
    void agregarCompra(const Producto& producto) {
        compras.push_back(producto);
    }

    // 1B) Método para pagar la cuenta
    void pagarCuenta() {
        double total = 0;
        cout << "Factura de " << nombre << ":" << endl;
        for (const auto& producto : compras) {
            cout << "- " << producto.getNombre() << " x" << producto.getCantidad() 
                 << " | $" << producto.getPrecio() * producto.getCantidad() << endl;
            total += producto.getPrecio() * producto.getCantidad();
        }
        cout << "Total a pagar: $" << total << endl;
    }
};
