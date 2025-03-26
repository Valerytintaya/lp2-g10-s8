#include "Tienda.cpp"

int main() {
    Tienda tienda;

    // Agregar productos a la tienda
    tienda.agregarProducto(Producto("Laptop", 1000, 5));
    tienda.agregarProducto(Producto("Mouse", 50, 10));

    // Registrar cliente
    Cliente cliente("Juan");
    tienda.registrarCliente(cliente);

    // Mostrar productos disponibles
    tienda.mostrarProductos();

    // Cliente intenta comprar productos
    tienda.venderProducto("Laptop", 1, cliente);
    tienda.venderProducto("Mouse", 15, cliente); // No hay suficiente stock

    // Cliente paga la cuenta
    cliente.pagarCuenta();

    return 0;
}
