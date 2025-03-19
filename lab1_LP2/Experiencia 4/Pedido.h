#ifndef PEDIDO_H
#define PEDIDO_H

#include "Producto.h"
#include <vector>
using namespace std;

class Pedido {
private:
    vector<Producto> listaDeProductos;
    vector<int> cantidadPorProducto;

public:
    Pedido();
    void agregarProducto(Producto producto, int cantidad);
    void mostrarPedido();

    vector<Producto> getListaDeProductos();
    vector<int> getCantidadPorProducto();
};

#endif
