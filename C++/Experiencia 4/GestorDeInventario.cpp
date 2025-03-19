#include "GestorDeInventario.h"
#include <iostream>

using namespace std;

void GestorDeInventario::agregarProducto(Producto nuevo) {
    productos.push_back(nuevo);
}

void GestorDeInventario::actualizarInventario(Pedido pedido) {
    vector<Producto> productosPedido = pedido.getListaDeProductos();
    vector<int> cantidadesPedido = pedido.getCantidadPorProducto();

    for (int i = 0; i < productosPedido.size(); i++) {
        for (int j = 0; j < productos.size(); j++) {
            if (productos[j].getNombre() == productosPedido[i].getNombre()) {
                if (productos[j].getCantidadEnInventario() < cantidadesPedido[i]) { 
                    cout << "Error: No hay suficiente stock de " << productos[j].getNombre() << endl;
                    return;
                }
                int nuevaCantidad = productos[j].getCantidadEnInventario() - cantidadesPedido[i];
                productos[j].setCantidadEnInventario(nuevaCantidad);
            }
        }
    }
}

void GestorDeInventario::mostrarInventario() {
    cout << "Inventario actual:\n";
    for (Producto p : productos) {
        cout << "- " << p.getNombre() << " | Precio: $" << p.getPrecio() << " | Stock: " << p.getCantidadEnInventario() << endl;
    }
}
