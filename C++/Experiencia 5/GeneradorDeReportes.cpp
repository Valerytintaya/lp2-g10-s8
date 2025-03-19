#include "GeneradorDeReportes.h"
#include <iostream>

GeneradorDeReportes::GeneradorDeReportes(GestorDeInventario* gestor)
    : gestor(gestor) {}

void GeneradorDeReportes::agregarPedidoAlHistorial(const Pedido& pedido) {
    historialPedidos.push_back(pedido);
}

void GeneradorDeReportes::reporteGeneral() const {
    std::cout << "\n=== Reporte General ===\n";

    std::cout << "\nInventario actual:\n";
    for (const auto& producto : gestor->getInventario()) {
        std::cout << "Producto: " << producto.getNombre()
                  << " - Stock: " << producto.getCantidadEnInventario() << "\n";
    }

    std::cout << "\nHistorial de pedidos:\n";
    for (const auto& pedido : historialPedidos) {
        for (const auto& item : pedido.getListaDeProductos()) {
            std::cout << "Producto: " << item.first.getNombre()
                      << " - Cantidad vendida: " << item.second << "\n";
        }
    }
}
