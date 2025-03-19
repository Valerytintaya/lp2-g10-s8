#include "Producto.h"
#include "Pedido.h"
#include <iostream>

using namespace std;

int main() {
    Producto producto1("Laptop", 1200.0, 5);
    Producto producto2("Mouse", 25.0, 20);
    Producto producto3("Teclado", 45.0, 15);

    Pedido pedido1;
    pedido1.agregarProducto(producto1, 1);
    pedido1.agregarProducto(producto2, 2);
    pedido1.agregarProducto(producto3, 1);

    pedido1.mostrarPedido();

    return 0;
}
