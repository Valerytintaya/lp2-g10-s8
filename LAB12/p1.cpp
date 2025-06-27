#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Producto {
private:
    string descripcion;
    int cantidad;

public:
    Producto() {}
    Producto(string des, int cant) : descripcion(des), cantidad(cant) {}

    string getDescripcion() const { return descripcion; }
    int getCantidad() const { return cantidad; }

    void setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad; }

    void mostrar() const {
        cout << "Descripción: " << descripcion << ", Cantidad: " << cantidad << endl;
    }
};

// Función para mostrar menú
void mostrarMenu() {
    cout << "\n--- Gestión de Inventario ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Actualizar cantidad\n";
    cout << "3. Buscar producto por código\n";
    cout << "4. Mostrar productos ordenados por descripción\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    map<string, Producto> inventario;
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            string codigo, descripcion;
            int cantidad;

            cout << "Ingrese código del producto: ";
            cin>>codigo;
            if (inventario.count(codigo)) {
                cout << "El producto ya existe\n";
            } else {
                cout << "Ingrese descripción: ";
                cin>>descripcion;
                cout << "Ingrese cantidad: ";
                cin >> cantidad;
                inventario[codigo] = Producto(descripcion, cantidad);
                cout << "Producto agregado con éxito.\n";
            }

        } else if (opcion == 2) {
            string codigo;
            int nuevaCantidad;

            if (!inventario.empty()){

            cout << "Ingrese código del producto a actualizar: ";
            cin>>codigo;

            
            if (inventario.count(codigo)) {
                cout << "Ingrese nueva cantidad: ";
                cin >> nuevaCantidad;
                inventario[codigo].setCantidad(nuevaCantidad);
                cout << "Cantidad actualizada.\n";
            } else {
                cout << "Producto no encontrado.\n";
            }
            }
            else{
                cout<<"map vacio"<<endl;
            }

        } else if (opcion == 3) {
            string codigo;
            if (!inventario.empty()){
            cout << "Ingrese código del producto a buscar: ";
            cin>>codigo;

            

            if (inventario.count(codigo)) {
                cout << "Producto encontrado:\n";
                inventario[codigo].mostrar();
            } else {
                cout << "Producto no encontrado.\n";
            }
            }
            else{
                cout<<"map vacio"<<endl;
            }

        } else if (opcion == 4) {
            if (!inventario.empty()){
            
            vector<pair<string, Producto>> productos(inventario.begin(), inventario.end());

            sort(productos.begin(), productos.end(), [](auto& a, auto& b) {
                return a.second.getDescripcion() < b.second.getDescripcion();
            });

            cout << "\n--- Lista de productos ordenada por descripción ---\n";
            for (auto& p : productos) {
                cout << "Código: " << p.first << " | ";
                p.second.mostrar();
            }

            }
            else{
                cout<<"map vacio"<<endl;
            }

        } else if (opcion == 5) {
            cout << "Saliendo del programa...\n";
        } else {
            cout << "Intente nuevamente.\n";
        }

    } while (opcion != 5);

    return 0;
}
