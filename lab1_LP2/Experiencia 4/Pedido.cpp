#include "Pedido.h"
#include <iostream>

using namespace std;

Pedido::Pedido() {}

void Pedido::agregarProducto(Producto producto, int cantidad) {
    listaDeProductos.push_back(producto);
    cantidadPorProducto.push_back(cantidad);
}

void Pedido::mostrarPedido() {
    cout << "Pedido:\n";
    for (int i = 0; i < listaDeProductos.size(); i++) {
        cout << "- " << listaDeProductos[i].getNombre() << " x" << cantidadPorProducto[i] << endl;
    }
}

vector<Producto> Pedido::getListaDeProductos() {
    return listaDeProductos;
}

vector<int> Pedido::getCantidadPorProducto() {
    return cantidadPorProducto;
}
