#include "GeneradorDeReportes.h"
#include <iostream>

using namespace std;

GeneradorDeReportes::GeneradorDeReportes(GestorDeInventario* inv) {
    inventario = inv;
}

void GeneradorDeReportes::agregarPedidoAlHistorial(Pedido pedido) {
    historialPedidos.push_back(pedido);
}

void GeneradorDeReportes::reporteVentas() {
    int totalVentas = 0;
    double ingresosTotales = 0.0;

    for (Pedido pedido : historialPedidos) {
        vector<Producto> productosPedido = pedido.getListaDeProductos();
        vector<int> cantidadesPedido = pedido.getCantidadPorProducto();

        for (int i = 0; i < productosPedido.size(); i++) {
            totalVentas += cantidadesPedido[i];
            ingresosTotales += productosPedido[i].getPrecio() * cantidadesPedido[i];
        }
    }

    cout << "Reporte de Ventas:\n";
    cout << "Total de productos vendidos: " << totalVentas << endl;
    cout << "Ingresos totales: $" << ingresosTotales << endl;
}

void GeneradorDeReportes::reporteInventarioBajo(int umbral) {
    cout << "Productos con inventario bajo (menor a " << umbral << " unidades):\n";
    for (Producto p : inventario->getProductos()) {
        if (p.getCantidadEnInventario() < umbral) {
            cout << "- " << p.getNombre() << " | Stock: " << p.getCantidadEnInventario() << endl;
        }
    }
}

void GeneradorDeReportes::reporteGeneral() {
    cout << "Reporte General:\n";
    inventario->mostrarInventario();
    reporteVentas();
}
