#ifndef GESTORDEINVENTARIO_H
#define GESTORDEINVENTARIO_H

#include "Producto.h"
#include "Pedido.h"
#include <vector>

class GestorDeInventario {
private:
    std::vector<Producto> productos;

public:
    void agregarProducto(const Producto& producto);
    Producto* buscarProducto(const std::string& nombre);
    void actualizarInventario(const Pedido& pedido);
    std::vector<Producto> getInventario() const;
};

#endif
