#include <iostream>
#include <vector>
#include <string>
#include <limits> // Para limpiar buffer

using namespace std;

// Estructuras de datos
struct Producto {
    string nombreProducto;
    double precio;
    int cantidadEnInventario;
};

struct Pedido {
    string nombreProductoSolicitado;
    int cantidadSolicitada;
};

// Función para limpiar buffer y evitar problemas con `cin`
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para registrar un producto
void registrarProducto(Producto &p) {
    cout << "Ingrese el nombre del producto: ";
    limpiarBuffer();
    getline(cin, p.nombreProducto);

    cout << "Ingrese el precio del producto: ";
    while (!(cin >> p.precio) || p.precio < 0) {
        cout << "Entrada inválida. Ingrese un precio válido: ";
        limpiarBuffer();
    }

    cout << "Ingrese la cantidad en inventario: ";
    while (!(cin >> p.cantidadEnInventario) || p.cantidadEnInventario < 0) {
        cout << "Entrada inválida. Ingrese una cantidad válida: ";
        limpiarBuffer();
    }
}

// Función para crear un pedido
void crearPedido(Pedido &ped) {
    cout << "Ingrese el nombre del producto solicitado: ";
    limpiarBuffer();
    getline(cin, ped.nombreProductoSolicitado);

    cout << "Ingrese la cantidad solicitada: ";
    while (!(cin >> ped.cantidadSolicitada) || ped.cantidadSolicitada <= 0) {
        cout << "Entrada inválida. Ingrese una cantidad válida: ";
        limpiarBuffer();
    }
}

// Función para imprimir los datos de un producto
void imprimirProducto(const Producto &p) {
    cout << "\n--- Detalles del Producto ---\n";
    cout << "Nombre: " << p.nombreProducto << endl;
    cout << "Precio: $" << p.precio << endl;
    cout << "Cantidad en Inventario: " << p.cantidadEnInventario << endl;
}

// Función para imprimir los datos de un pedido
void imprimirPedido(const Pedido &ped) {
    cout << "\n--- Detalles del Pedido ---\n";
    cout << "Producto Solicitado: " << ped.nombreProductoSolicitado << endl;
    cout << "Cantidad Solicitada: " << ped.cantidadSolicitada << endl;
}

int main() {
    vector<Producto> inventario;
    Pedido pedido;
    int numProductos;

    cout << "Ingrese el numero de productos a registrar: ";
    while (!(cin >> numProductos) || numProductos <= 0) {
        cout << "Entrada inválida. Ingrese un número válido: ";
        limpiarBuffer();
    }

    for (int i = 0; i < numProductos; ++i) {
        Producto nuevoProducto;
        registrarProducto(nuevoProducto);
        inventario.push_back(nuevoProducto);
    }

    crearPedido(pedido);

    // Listar productos registrados
    cout << "\nInventario registrado:\n";
    for (const auto &prod : inventario) {
        imprimirProducto(prod);
    }

    imprimirPedido(pedido);

    return 0;
}
