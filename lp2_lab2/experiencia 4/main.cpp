#include "Factura.cpp"

int main() {
    // Crear productos
    Producto p1("Laptop", 1000, 2);
    Producto p2("Mouse", 50, 5);
    Producto p3("Teclado", 80, 0); // Producto sin stock

    // Crear factura
    Factura factura;
    factura.agregarProducto(p1);
    factura.agregarProducto(p2);
    factura.agregarProducto(p3); // No se agregará porque no hay stock

    // Mostrar factura
    factura.mostrarFactura();

    // Calcular total con 10% de descuento y 16% de IVA
    double total = factura.calcularTotal(10, 16);
    cout << "Total con descuento e impuestos: $" << total << endl;

    return 0;
}
