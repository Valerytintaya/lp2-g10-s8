#include <iostream>
#include <vector>
using namespace std;

// Incluir Producto antes de usarlo
#include "Producto.cpp"

// A) Crear una clase Factura
class Factura {
private:
    vector<Producto> productos; // Lista de productos en la factura

public:
    // 1A) Método para agregar productos a la factura
    void agregarProducto(const Producto& producto) {
        // 1B) Validar que el producto esté disponible antes de agregarlo a la factura
        if (producto.getCantidad() > 0) { 
            productos.push_back(producto);
            cout << "Producto agregado a la factura." << endl;
        } else {
            cout << "Error: Producto '" << producto.getNombre() << "' no está disponible en stock." << endl;
        }
    }

    // Método para mostrar la factura
    void mostrarFactura() {
        cout << "Factura: " << endl;
        for (const auto& producto : productos) {
            cout << "- " << producto.getNombre() << " | Precio: $" << producto.getPrecio() 
                 << " | Cantidad: " << producto.getCantidad() << endl;
        }
    }

    // 2B) Método para calcular el total con descuentos e impuestos
    double calcularTotal(double descuento, double impuesto) {
        double total = 0;

        // Calcular el subtotal sumando los precios de todos los productos
        for (const auto& producto : productos) {
            total += producto.getPrecio() * producto.getCantidad();
        }

        // Aplicar descuento (porcentaje)
        total -= (total * (descuento / 100));

        // Aplicar impuesto (porcentaje)
        total += (total * (impuesto / 100));

        return total;
    }
};
