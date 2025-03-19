#ifndef GESTORDEINVENTARIO_H
#define GESTORDEINVENTARIO_H

#include "Producto.h"
#include "Pedido.h"
#include <vector>
using namespace std;

class GestorDeInventario {
private:
    vector<Producto> productos;

public:
    void agregarProducto(Producto nuevo);
    void actualizarInventario(Pedido pedido);
    void mostrarInventario();
};

#endif
