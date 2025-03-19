#include "GestorDeInventario.h"
#include <iostream>

using namespace std;

int main() {
    GestorDeInventario inventario;

    Producto producto1("Laptop", 1200.0, 10);
    Producto producto2("Mouse", 25.0, 15);
    Producto producto3("Teclado", 45.0, 20);

    inventario.agregarProducto(producto1);
    inventario.agregarProducto(producto2);
    inventario.agregarProducto(producto3);

    Pedido pedido1;
    pedido1.agregarProducto(producto1, 2);
    pedido1.agregarProducto(producto2, 3);

    inventario.actualizarInventario(pedido1);

    inventario.mostrarInventario();

    return 0;
}
