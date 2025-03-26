#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 100;

class Producto {
    private: 
        string nombre;
        int cantidad;
        double precio;
    public:
        Producto() : nombre(""), cantidad(0), precio(0.0) {}
        Producto(string n, int c, double p) : nombre(n), cantidad(c), precio(p) {}

        string getNombre(){return nombre;} ;
        int getCantidad(){return cantidad;};
        double getPrecio(){return precio;};

        void setCantidad(int cantidadRestar){
            cantidad-=cantidadRestar;
        };
};

class Inventario {
private:
    Producto productos[MAX_PRODUCTOS];
    int totalProductos;

public:
    Inventario() : totalProductos(0) {}

    void agregarProducto(string nombre, int cantidad, double precio) {
        if (totalProductos < MAX_PRODUCTOS) {
            productos[totalProductos] = Producto(nombre, cantidad, precio);
            totalProductos++;
        } else {
            cout << "Inventario lleno. No se puede agregar más productos.\n";
        }
    }
    
    void mostrarInventario() {
        cout << "\nInventario:" << endl;
        for (int i = 0; i < totalProductos; i++) {
            cout << productos[i].getNombre() << " - " << productos[i].getCantidad()<< " unidades - $" << productos[i].getPrecio() << endl;
        }
    }
    
    bool realizarPedido(string nombre, int cantidad) {
        for (int i = 0; i < totalProductos; i++) {
            if (productos[i].getNombre()== nombre && productos[i].getCantidad() >= cantidad) {
                productos[i].setCantidad(cantidad);
                return true;
            }
        }
        return false;
    }
};

int main() {
    Inventario inventario;
    int opcion;
    string nombre;
    int cantidad;
    double precio;
    
    do {
        cout << "\n1. Agregar Producto\n2. Mostrar Inventario\n3. Realizar Pedido\n4. Salir\nOpción: ";
        cin >> opcion;
        cin.ignore();
        
        switch (opcion) {
            case 1:
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Cantidad: ";
                cin >> cantidad;
                cout << "Precio: ";
                cin >> precio;
                inventario.agregarProducto(nombre, cantidad, precio);
                break;
            case 2:
                inventario.mostrarInventario();
                break;
            case 3:
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Cantidad: ";
                cin >> cantidad;
                if (inventario.realizarPedido(nombre, cantidad))
                    cout << "Pedido exitoso!\n";
                else
                    cout << "Stock insuficiente!\n";
                break;
        }
    } while (opcion != 4);
    
    return 0;
}
