#include <iostream>
#include <vector>
using namespace std;

#include "Cliente.cpp"
#include "Producto.cpp"

// 1) Crear una clase Tienda
class Tienda {
private:
    vector<Producto> productosDisponibles; // 1A) Lista de productos disponibles
    vector<Cliente> clientes; // 1A) Lista de compras de clientes

public:
    void agregarProducto(const Producto& producto) {
        productosDisponibles.push_back(producto);
    }

    void registrarCliente(const Cliente& cliente) {
        clientes.push_back(cliente);
    }

    // 2A) Método que un cliente usa para comprar productos
    bool venderProducto(string nombreProducto, int cantidad, Cliente& cliente) {
        for (auto& producto : productosDisponibles) {
            if (producto.getNombre() == nombreProducto) {
                // 2B) Validar que haya stock suficiente antes de vender
                if (producto.getCantidad() >= cantidad) {
                    producto.setCantidad(producto.getCantidad() - cantidad);
                    cliente.agregarCompra(Producto(nombreProducto, producto.getPrecio(), cantidad));
                    cout << "Compra realizada: " << nombreProducto << " x" << cantidad << endl;
                    return true;
                } else {
                    cout << "No hay suficiente stock de " << nombreProducto << "." << endl;
                    return false;
                }
            }
        }
        cout << "Producto no encontrado en la tienda." << endl;
        return false;
    }

    void mostrarProductos() {
        cout << "Productos disponibles en la tienda:" << endl;
        for (const auto& producto : productosDisponibles) {
            cout << "- " << producto.getNombre() << " | Precio: $" << producto.getPrecio() 
                 << " | Stock: " << producto.getCantidad() << endl;
        }
    }
};
