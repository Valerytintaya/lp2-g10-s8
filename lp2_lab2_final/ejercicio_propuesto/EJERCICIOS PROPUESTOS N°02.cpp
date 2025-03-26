#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTOS = 20;
const int MAX_FACTURAS = 20;
class Producto {
private:
    string id;
    string nombre;
    int cantidad;
    double precio;

public:
    Producto() : id(""), nombre(""), cantidad(0), precio(0.0) {}
    Producto(string i, string n, int c, double p) : id(i), nombre(n), cantidad(c), precio(p) {}

    string getID() { return id; }
    string getNombre() { return nombre; }
    int getCantidad() { return cantidad; }
    double getPrecio() { return precio; }

    void setCantidadR(int cantidadRestar) {
        cantidad -= cantidadRestar;
    }

    void setCantidadS(int cantidads) {
        cantidad += cantidads;
    }
};

// Estructuras para productos disponibles y agotados
struct Pdisponibles {
    string id;
    string nombre;
    int cantidad;
    double precio;
};

struct Pagotados {
    string id;
    string nombre;
    int cantidad;
    double precio;
};
struct Factura {
    string cliente;
    string idProducto;
    int cantidad;
    double total;
};

class Inventario {
private:
    Producto productos[MAX_PRODUCTOS];
    Factura facturas[MAX_FACTURAS];
    Pagotados* pagotao[MAX_PRODUCTOS];
    int totalProductos;
    int totalDispo;
    int totalAgot;
    int totalFacturas;

public:
    Pdisponibles* pdispo[MAX_PRODUCTOS];
    Inventario() : totalProductos(0), totalDispo(0), totalAgot(0), totalFacturas(0) {
        for (int i = 0; i < MAX_PRODUCTOS; i++) {
            pdispo[i] = nullptr;
            pagotao[i] = nullptr;
        }
    }

    ~Inventario() {
        for (int i = 0; i < totalProductos; i++) {
            delete pdispo[i];
            delete pagotao[i];
        }
    }

    int estar(string iddd){
        for (int i=0; i<totalDispo; i++){
            if (pdispo[i] != nullptr && pdispo[i]->id == iddd) {
                return 1;
            }
        }
        cout<< "el prodcuto no esta disponible"<<endl;
        return -1;
    }

    void actualizarstock(string idd, int cantidads){
        for (int i=0; i<totalDispo; i++){
            if (pdispo[i] != nullptr && pdispo[i]->id == idd) {
                pdispo[i]->cantidad+= cantidads;
                cout << "Producto " << idd << " se actualizo su stock.\n" << endl;
                return;
            }
        }
    }

    void actualizarstockHabidoagotado(string idd, int cantidadSumar) {
        for (int i = 0; i < totalProductos; i++) {
            if (pagotao[i] != nullptr && pagotao[i]->id == idd) {
                pdispo[i] = new Pdisponibles{pagotao[i]->id, pagotao[i]->nombre, cantidadSumar, pagotao[i]->precio};
                totalDispo++;
                delete pagotao[i];
                pagotao[i] = nullptr;
                totalAgot--;
                cout << "Producto " << idd << " movido de agotados a disponibles.\n" << endl;
                return;
            }
            else if (pdispo[i] != nullptr && pdispo[i]->id == idd) {
                actualizarstock(idd, cantidadSumar);
            }
        }
    }

    int verificar(string _id) {
        string op;
        int cantidad;
        for (int i = 0; i < totalProductos; i++) {
            if ((pdispo[i] != nullptr && pdispo[i]->id == _id) || (pagotao[i] != nullptr && pagotao[i]->id == _id)) {
                cout << "El producto ya se encuentra en productos disponibles o agotados..." << endl;
                cout << "Desea agregar unidades al stock (S/N): ";
                cin >> op;
                if (op == "S") {
                    cout << "Cantidad que desea agregar: ";
                    cin >> cantidad;
                    actualizarstockHabidoagotado(_id, cantidad);
                    return -1;
                } else {
                    cout << "No se actualizó ningún stock..." << endl;
                }
            }
        }
        return 1;
    }

    void agregarProducto(string id, string nombre, int cantidad, double precio) {
        if (verificar(id) == -1) {
            return;
        } else if (verificar(id) == 1) {
            if (totalProductos < MAX_PRODUCTOS) {
                productos[totalProductos] = Producto(id, nombre, cantidad, precio);
                pdispo[totalProductos] = new Pdisponibles{id, nombre, cantidad, precio};
                totalDispo++;
                totalProductos++;
            } else {
                cout << "Inventario lleno. No se puede agregar más productos.\n";
            }
        }
    }

    void ingresarProductos() {
        int numProductos;
        cout << "Cuantos productos desea ingresar?: ";
        cin >> numProductos;
        cin.ignore();
        for (int i = 0; i < numProductos; i++) {
            string id, nombre;
            int cantidad;
            double precio;
            cout << "ID del producto: ";
            getline(cin, id);
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Cantidad: ";
            cin >> cantidad;
            cout << "Precio: ";
            cin >> precio;
            cin.ignore();
            agregarProducto(id, nombre, cantidad, precio);
        }
    }
    void mostrarInventariodisponible() {
        cout << "\n=== Inventario Disponible ===" << endl;
        for (int i = 0; i < totalDispo+1; i++) {
            if (pdispo[i] != nullptr) {
                cout << "ID: " << pdispo[i]->id
                     << " | " << pdispo[i]->nombre
                     << " - " << pdispo[i]->cantidad << " unidades - $"
                     << pdispo[i]->precio << endl;
            }
        }
    }

    void mostrarInventarioagotado() {
        cout << "\n=== Inventario Productos Agotados ===" << endl;
        for (int i = 0; i < totalAgot; i++) {
            if (pagotao[i] != nullptr) {
                cout << "ID: " << pagotao[i]->id
                     << " | " << pagotao[i]->nombre << endl;
            }
        }
    }
    void agregarFactura(string cliente, string id, int cantidad, double precio) {
        if (totalFacturas < MAX_FACTURAS) {
            facturas[totalFacturas] = {cliente, id, cantidad, precio * cantidad};
            totalFacturas++;
        }
    }

    void mostrarFacturas() {
        cout << "\n=== Facturas de Clientes ===\n";
        for (int i = 0; i < totalFacturas; i++) {
            cout << "Cliente: " << facturas[i].cliente << " | Producto: " << facturas[i].idProducto
                 << " | Cantidad: " << facturas[i].cantidad << " | Total: $" << facturas[i].total << endl;
        }
    }

    void realizarPedido(string cliente, string _id, int cantidad) {
        for (int i = 0; i < totalDispo; i++) {
            if (pdispo[i] != nullptr && pdispo[i]->id == _id && pdispo[i]->cantidad >= cantidad) {
                pdispo[i]->cantidad -= cantidad;
                agregarFactura(cliente, _id, cantidad, pdispo[i]->precio);
                if (pdispo[i]->cantidad == 0) {
                    pagotao[i] = new Pagotados{pdispo[i]->id, pdispo[i]->nombre, 0, pdispo[i]->precio};
                    delete pdispo[i];
                    pdispo[i] = nullptr;
                    totalDispo--;
                    totalAgot++;
                }
                return;

            }
        }
        cout<<"la cantidad excede...no se resto nada"<<endl;
        return ;
    }

    void ingresarPedidos() {
        int numPedidos;
        cout << "Cuantos pedidos desea ingresar?: ";
        cin >> numPedidos;
        cin.ignore();
        for (int i = 0; i < numPedidos; i++) {
            string cliente, id;
            int cantidad;
            cout << "Nombre del Cliente: ";
            getline(cin, cliente);
            cout << "ID del producto: ";
            getline(cin, id);
            if (estar(id)==-1){
                return;
            }
            cout << "Cantidad: ";
            cin >> cantidad;
            cin.ignore();
            realizarPedido(cliente, id, cantidad);
        }
    }



    void ingresarCambiarstock() {
        string id;
        int cantidad;
        cout << "ID del producto: ";
        getline(cin, id);
        if (estar(id)==-1){
            return;
        }
        cout << "Cantidad a sumar: ";
        cin >> cantidad;
        cin.ignore();
        actualizarstock(id, cantidad);
    }
};
int main() {
    Inventario inventario;
    int opcion;

    do {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Mostrar Stock Disponible" << endl;
        cout << "3. Mostrar Stock Agotado" << endl;
        cout << "4. Realizar Pedido" << endl;
        cout << "5. Mostrar Facturas" << endl;
        cout << "6. actualizar stock"<<endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                inventario.ingresarProductos();
                break;
            case 2:
                inventario.mostrarInventariodisponible();
                break;
            case 3:
                inventario.mostrarInventarioagotado();
                break;
            case 4:
                inventario.ingresarPedidos();
                break;
            case 5:
                inventario.mostrarFacturas();
                break;
            case 6:
                inventario.ingresarCambiarstock();
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}
