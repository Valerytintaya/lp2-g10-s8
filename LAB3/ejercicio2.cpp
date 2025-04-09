#include <iostream>
#include <string>
using namespace std;
const int MAX=10;
class Clientes;
class Proveedor{
    public:
    string nombre, contacto;
    Proveedor(string n,string c): nombre(n), contacto(c) {}

    void mostrarDatos(){
        cout << "Proveedor: " << nombre << " - Contacto: " << contacto << endl;
    }

};
class Productos{
    public:
    string codigo, descripcion;
    float precio; 
    Proveedor* proveedor;

    Productos(string c, string d, float p, Proveedor* pro)
    : codigo(c), descripcion(d), precio(p), proveedor(pro){}

    void mostrarInfo(){
        cout << "Codigo: " << codigo << " - Descripcion: " << descripcion
              << " - Precio: " << precio
              << " - Proveedor: " << proveedor->nombre << std::endl;
    }
};
class Pago{
    public:
    float monto;
    string fecha;
    Clientes* cliente;

    Pago(float m, string f, Clientes* c)
    : monto(m), fecha(f), cliente(c) {}

    void mostrarPago(){
        cout << "Pago de $: " << monto << " el " << fecha<<endl;
    }
};
class Ventas {
    public:
    string nfactura, fecha;
    Clientes* cliente; //bidireccional
    Productos* pVendidos[MAX]; 
    int numP;//composicion

    Ventas(string n, string f, Clientes* c): nfactura(n), fecha(f), cliente(c), numP(0){}

    void agregarProducto(Productos* nuevo){
        if (numP<MAX){
            pVendidos[numP++]= nuevo;
            cout<<"producto agregado a venta.."<<endl;
        } else{
            cout<<"productos excedidos..."<<endl;
            return;
        }
    }

    void mostrarVenta();
};

class Clientes{
    public:
    string nombre, direc, telefono;
    Ventas* ventas[MAX]; //bidireccional
    Pago* pagos[MAX];
    int numVenta, numPago;

    Clientes(string n, string d, string t) : nombre(n), direc(d), telefono(t), numVenta(0), numPago(0){}
    //lisat de compras

    void agregarVenta(Ventas* nueva){
        if (numVenta<MAX){
            ventas[numVenta++]= nueva;
            cout<<"venta agregada a cliente.."<<endl;
        } else{
            cout<<"ventas excedidas..."<<endl;
            return;
        }
    }

    void agregarPago(Pago* nuevo){
        if (numPago<MAX){
            pagos[numPago++]= nuevo;
            cout<<"pago agregada a cliente.."<<endl;
        } else{
            cout<<"pagos excedidos..."<<endl;
            return;
        }
    }

    void mostrarHistorial() {
        cout << "\n--- HISTORIAL DEL CLIENTE: " << nombre << " ---\n";
    
        cout << "\nVENTAS:\n";
        if (numVenta == 0) {
            cout << "No hay ventas registradas.\n";
        }
        for (int i = 0; i < numVenta; i++) {
            ventas[i]->mostrarVenta();
            cout << "----------------------\n";
        }
    
        cout << "\nPAGOS:\n";
        if (numPago == 0) {
            cout << "No hay pagos registrados.\n";
        }
        for (int i = 0; i < numPago; i++) {
            pagos[i]->mostrarPago();
        }
    }
};

void Ventas:: mostrarVenta(){
    cout<<"Factura: "<<nfactura <<" - Fecha: "<< fecha;
    cout<<"- Cliente: "<<cliente->nombre<<endl;
    cout<<"Productos Vendidos: "<<endl;
    for (int i=0; i<numP; i++){
        cout<<"- "<< pVendidos[i]->codigo;
        cout<<"- "<< pVendidos[i]->descripcion;
        cout<<"- "<< pVendidos[i]->precio<<endl;
    }
}
int main() {
    Clientes* clientes[MAX];
    Productos* productos[MAX];
    Proveedor* proveedores[MAX];
    int numClientes = 0, numProductos = 0, numProveedores = 0;

    int opcion;
    do {
        cout << "\n--- MENU TIENDA DE ROPA ---\n";
        cout << "1. Registrar Cliente\n";
        cout << "2. Registrar Proveedor\n";
        cout << "3. Registrar Producto\n";
        cout << "4. Registrar Venta\n";
        cout << "5. Mostrar historial de cliente\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre, dire, tel;
                int n;
                cout<<"numero de clientes a agregar: ";
                cin>>n;

                for (int i=0; i<n; i++){
                    cout<<"nombre: "; cin>>nombre;
                    cout<<"direccion: "; cin>>dire;
                    cout<<"telefono: "; cin>>tel;
                    clientes[numClientes++]= new Clientes(nombre, dire, tel);
                }
                break;
            }
            case 2:{
                string nombre, con;
                int n;
                cout<<"numero de proveedores a agregar: ";
                cin>>n;

                for (int i=0; i<n; i++){
                    cout<<"nombre: "; cin>>nombre;
                    cout<<"contacto/ telefono: "; cin>>con;
                    proveedores[numProveedores++]= new Proveedor(nombre, con);
                }
            
                break;
            }
            case 3:{
                string codigo, descrip;
                float precio;
                int n, indice;
                cout<<"numero de productos a agregar: ";
                cin>>n;

                for (int i=0; i<n; i++){
                    cout<<"codigo: "; cin>>codigo;
                    cout<<"descripcion: "; cin>>descrip;
                    cout<<"precio: "; cin>>precio;

                    cout <<" ===PROVEEDORES==="<<endl;
                    for(int j=0; j<numProveedores; j++){
                        cout<<j+1 <<"| ";
                        proveedores[j]->mostrarDatos();
                    }

                    cout << "elija proveedor(indice): "; 
                    cin>>indice;
                    Proveedor* p= proveedores[indice-1];
                    productos[numProductos++]= new Productos(codigo, descrip, precio, p);
                }
            
                break;
            }

            case 4: {
                if (numClientes == 0 || numProductos == 0) {
                    cout << "Debe registrar al menos un cliente y un producto antes de crear una venta.\n";
                    break;
                }
            
                string factura, fecha;
                int indiceCliente, indiceProducto;
            
                cout << "Numero de factura: ";
                cin >> factura;
                cout << "Fecha (DD/MM/AAAA): ";
                cin >> fecha;
            
                // Mostrar clientes
                cout << "\n--- Clientes Disponibles ---\n";
                for (int i = 0; i < numClientes; i++) {
                    cout << i + 1 << "| " << clientes[i]->nombre << endl;
                }
                cout << "Seleccione cliente (indice): ";
                cin >> indiceCliente;
                Clientes* c = clientes[indiceCliente - 1];
            
                // Crear nueva venta
                Ventas* nuevaVenta = new Ventas(factura, fecha, c);
            
                // Agregar productos
                int agregarMas;
                float monto=0.0;
                do {
                    cout << "\n--- Productos Disponibles ---\n";
                    for (int i = 0; i < numProductos; i++) {
                        cout << i + 1 << "| ";
                        productos[i]->mostrarInfo();
                    }
                    cout << "Seleccione producto (indice): ";
                    cin >> indiceProducto;
                    nuevaVenta->agregarProducto(productos[indiceProducto - 1]);
                    monto+=productos[indiceProducto-1]->precio;
    
                    cout << "¿Desea agregar otro producto? (1: Si / 0: No): ";
                    cin >> agregarMas;
                } while (agregarMas == 1);

                Pago* nuevoPago=  new Pago(monto, fecha, c);
                // Asociar la venta al cliente
                c->agregarVenta(nuevaVenta);
                c->agregarPago(nuevoPago);
                cout << "Venta registrada con exito.\n";
                break;
            }
            case 5: {
                if (numClientes == 0) {
                    cout << "No hay clientes registrados.\n";
                    break;
                }
            
                cout << "\n--- Clientes Registrados ---\n";
                for (int i = 0; i < numClientes; i++) {
                    cout << i + 1 << ". " << clientes[i]->nombre << endl;
                }
            
                int indice;
                cout << "Seleccione un cliente para ver su historial (indice): ";
                cin >> indice;
            
                if (indice >= 1 && indice <= numClientes) {
                    clientes[indice - 1]->mostrarHistorial();
                } else {
                    cout << "Indice invalido.\n";
                }
                break;
            }
            
        }
    } while (opcion != 0);
}
