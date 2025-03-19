#include "Producto.h"
#include "Pedido.h"
#include "GestorDeInventario.h"
#include "GeneradorDeReportes.h"
#include <iostream>

using namespace std;

int main() {
    GestorDeInventario gestor;
    GeneradorDeReportes reportes(&gestor);
    int opcion;

    do {
        cout << "\n=== Sistema de Gestión de Inventario y Pedidos ===\n";
        cout << "1. Registrar un nuevo producto\n";
        cout << "2. Crear y procesar un nuevo pedido\n";
        cout << "3. Generar reportes de ventas/inventario\n";
        cout << "4. Buscar un producto por nombre o código\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                double precio;
                int cantidad;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                cout << "Ingrese el precio del producto: ";
                cin >> precio;
                cout << "Ingrese la cantidad en inventario: ";
                cin >> cantidad;
                gestor.agregarProducto(Producto(nombre, precio, cantidad));
                break;
            }
            case 2: {
                Pedido pedido;
                int cantidad;
                string nombreProducto;
                char continuar;

                do {
                    cout << "Ingrese el nombre del producto a comprar: ";
                    cin >> nombreProducto;
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidad;

                    Producto* producto = gestor.buscarProducto(nombreProducto);
                    if (producto) {
                        double precioFinal = producto->getPrecio();

                        if (cantidad > 10) {
                            precioFinal *= 0.9;
                            cout << "Descuento aplicado. Nuevo precio por unidad: " << precioFinal << endl;
                        }

                        pedido.agregarProducto(*producto, cantidad);
                    } else {
                        cout << "Producto no encontrado en inventario.\n";
                    }

                    cout << "¿Desea agregar otro producto al pedido? (s/n): ";
                    cin >> continuar;
                } while (continuar == 's' || continuar == 'S');

                gestor.actualizarInventario(pedido);
                reportes.agregarPedidoAlHistorial(pedido);
                break;
            }
            case 3:
                reportes.reporteGeneral();
                break;
            case 4: {
                string criterio;
                cout << "Ingrese el nombre o código del producto a buscar: ";
                cin >> criterio;
                Producto* encontrado = gestor.buscarProducto(criterio);
                if (encontrado) {
                    cout << "Producto encontrado: " << encontrado->getNombre()
                         << ", Precio: " << encontrado->getPrecio()
                         << ", Stock: " << encontrado->getCantidadEnInventario() << endl;
                } else {
                    cout << "Producto no encontrado.\n";
                }
                break;
            }
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}

