#include "Producto.h"
#include "Pedido.h"
#include "GestorDeInventario.h"
#include "GeneradorDeReportes.h"
#include <iostream>

using namespace std;

int main() {
    GestorDeInventario gestor;
    GeneradorDeReportes reportes(&gestor);

    Producto p1("Laptop", 1200.00, 10);
    Producto p2("Mouse", 25.00, 50);
    Producto p3("Teclado", 45.00, 30);
    Producto p4("Monitor", 300.00, 15);

    gestor.agregarProducto(p1);
    gestor.agregarProducto(p2);
    gestor.agregarProducto(p3);
    gestor.agregarProducto(p4);

    Pedido pedido1;
    pedido1.agregarProducto(p1, 2);
    pedido1.agregarProducto(p2, 5);
    gestor.actualizarInventario(pedido1);
    reportes.agregarPedidoAlHistorial(pedido1);

    Pedido pedido2;
    pedido2.agregarProducto(p3, 3);
    pedido2.agregarProducto(p4, 1);
    gestor.actualizarInventario(pedido2);
    reportes.agregarPedidoAlHistorial(pedido2);

    Pedido pedido3;
    pedido3.agregarProducto(p1, 1);
    pedido3.agregarProducto(p2, 2);
    pedido3.agregarProducto(p3, 1);
    gestor.actualizarInventario(pedido3);
    reportes.agregarPedidoAlHistorial(pedido3);

    Pedido pedido4;
    pedido4.agregarProducto(p4, 3);
    gestor.actualizarInventario(pedido4);
    reportes.agregarPedidoAlHistorial(pedido4);

    reportes.reporteGeneral();

    return 0;
}
