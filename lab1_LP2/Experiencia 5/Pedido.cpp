#include "Pedido.h"

void Pedido::agregarProducto(const Producto& producto, int cantidad) {
    listaDeProductos.push_back({producto, cantidad});
}

std::vector<std::pair<Producto, int>> Pedido::getListaDeProductos() const {
    return listaDeProductos;
}
