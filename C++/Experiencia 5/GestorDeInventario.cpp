#include "GestorDeInventario.h"

void GestorDeInventario::agregarProducto(const Producto& producto) {
    productos.push_back(producto);
}

Producto* GestorDeInventario::buscarProducto(const std::string& nombre) {
    for (auto& producto : productos) {
        if (producto.getNombre() == nombre) {
            return &producto;
        }
    }
    return nullptr;
}

void GestorDeInventario::actualizarInventario(const Pedido& pedido) {
    for (const auto& item : pedido.getListaDeProductos()) {
        Producto* producto = buscarProducto(item.first.getNombre());
        if (producto) {
            int nuevaCantidad = producto->getCantidadEnInventario() - item.second;
            if (nuevaCantidad >= 0) {
                producto->setCantidadEnInventario(nuevaCantidad);
            }
        }
    }
}

std::vector<Producto> GestorDeInventario::getInventario() const {
    return productos;
}
