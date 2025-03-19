#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <vector>

class Pedido {
private:
    std::vector<std::pair<Producto, int>> listaDeProductos;

public:
    void agregarProducto(const Producto& producto, int cantidad);
    std::vector<std::pair<Producto, int>> getListaDeProductos() const;
};

#endif
