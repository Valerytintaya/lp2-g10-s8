#include "Pedido.h"
#include <iostream>

using namespace std;

Pedido::Pedido() {
    estadoDelPedido = "Pendiente";
}

void Pedido::agregarProducto(Producto producto, int cantidad) {
    listaDeProductos.push_back(producto);
    cantidadPorProducto.push_back(cantidad);
}

void Pedido::mostrarPedido() {
    cout << "Estado del pedido: " << estadoDelPedido << endl;
    for (int i = 0; i < listaDeProductos.size(); i++) {
        cout << "- " << listaDeProductos[i].getNombre() << " x" << cantidadPorProducto[i] << endl;
    }
}
