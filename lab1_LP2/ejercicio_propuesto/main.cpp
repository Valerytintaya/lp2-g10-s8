#include <iostream>
#include <string>
using namespace std;

const int max_pro=10;
class Producto{
    private:
    // ATRIBUTOS
        string id, nombre;
        float precio;
        int cantidadStock;
    
    public:
        //constructor con parametros
        Producto(string _id="00", string _nombre= "desconocido",float _precio=0.0, int _cantidadStock=0){
            id= _id;
            nombre=_nombre;
            precio=_precio;
            cantidadStock=_cantidadStock;
        }
        // set , get en cantidad producto
        int getCantidadStock(){return cantidadStock;}
        void setCantidadStock(int nuevaCantidad){
            if (nuevaCantidad>=0){
                cantidadStock=nuevaCantidad;
                cout<<"\n Nueva cantidad ingresada"<<endl;
            }
            else{
                cout<<"\n Cantidad invalida {Prodcuto-stock}"<<endl;
            }
        }

        // set , get en precio
        float getprecio(){return precio;}
        void setprecio(float nuevaCantidad){
            if (nuevaCantidad>0){
                precio=nuevaCantidad;
                cout<<"\n Nueva cantidad ingresada"<<endl;
            }
            else{
                cout<<"\n Cantidad invalida {Prodcuto-precio}"<<endl;
            }
        }

        // set , get en nombre
        string getnombre(){return nombre;}
        void setnombre(string nueva){nombre=nueva;}

        // set , get en ID
        string getId(){return id;}
        void setId(string nueva){id=nueva;}

        

        void mostrar_producto(){ //muestra el producto y eso
            cout<<"ID: "<<id<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"precio: "<<precio<<endl;
            cout<<"Stock: "<<cantidadStock<< " unidades "<<endl;
        }
        
};

class Inventario {
    private:
        Producto productos[max_pro];
        int totalproductos;
    public: 
        Inventario(){
            totalproductos=0;
        }

        int gettotalproductos(){return totalproductos;}

        void agregar_producto(string id, string nombre, float precio, int cantidadStock){
            if (totalproductos<max_pro){
                for (int x=0; x<totalproductos+1;x++){
                    if (productos[x].getId()==id){
                        cout<<"\nproducto con ID "<< id <<" ya ESTA EN LA LISTA..."<<endl;
                        return;
                    }
                }
                productos[totalproductos]= Producto(id, nombre, precio, cantidadStock);
                totalproductos+=1;
                cout<<"\nProducto AGREGADO..."<<endl;
            }
            else{
                cout<<"la cantidad de productos excede de "<<max_pro<<endl;
            }
        }

        void eliminar_producto(string id){
            for (int x=0; x<totalproductos;x++){
                if (productos[x].getId()==id){
                    for (int j =x;j< totalproductos-1; j++ ){
                        productos[j]=productos[j+1];
                    }
                    cout<<"producto con ID "<< id << " eliminado..."<<endl;
                    totalproductos--;
                    return;
                }
            }
            cout<<"no se encuentra el producto.. "<< endl;
        }

        void actualizar_stock(string id, int nuevo_cantidad){
            for (int x=0; x<totalproductos;x++){
                if (productos[x].getId()==id){
                    productos[x].setCantidadStock(nuevo_cantidad);
                    cout<<"\nproducto con ID "<< id << "| nombre: "<<productos[x].getnombre()<<"stock actualizado"<<endl;
                    return;
                }
            }
        }

        void mostrar_stock(){
            if (totalproductos==0){
                cout<<"\nningun producto ha sido agregado / LISTA VACIA"<<endl;

            }
            else {
                for (int i=0; i<totalproductos; i++){
                    cout<<"--------------------------------------------"<<endl;
                    cout<<"\t.:PRODUCTO "<< i+1<<":."<<endl;
                    productos[i].mostrar_producto();
                }
            }
        }

        int buscar_producto(string id) {
            for (int x = 0; x < totalproductos; x++) {
                if (productos[x].getId() == id) {
                    return x; // Retorna el índice del producto en el array
                }
            }
            return -1; // Indica que el producto no fue encontrado
        }

        Producto* obtenerProducto(string id) {
            int index = buscar_producto(id);
            if (index != -1) {
                return &productos[index];
            }
            return nullptr;
        }

        ~Inventario() {
            cout << "Inventario destruido "  << endl;
        }
};

struct RegistroVenta {
    string idProducto;
    string nombreProducto;
    int cantidadVendida;
    float totalVenta;
};

class Venta {
    private:
        RegistroVenta* ventas[15];
        Inventario* inventario;
        float totalVenta;
        int cantidad_ventas;
    
    public: 
        float get_venta_total(){return totalVenta;};
        void set_venta_total(float venta_adicionar){totalVenta+=venta_adicionar;};


        Venta(Inventario& inv) { 
            inventario = &inv; 
            totalVenta = 0.0; 
            cantidad_ventas=0;
        }
    
        void registrarVenta(string id, int cantidadVender) {
            Producto* producto = inventario->obtenerProducto(id);
            if (producto != nullptr) {
                if (producto->getCantidadStock() >= cantidadVender) {
                    float precio = producto->getprecio();
                    producto->setCantidadStock(producto->getCantidadStock() - cantidadVender);
                    float venta_ini=precio * cantidadVender;
                    totalVenta += venta_ini;
                    cout << "Venta registrada: " << cantidadVender << " unidades de " << producto->getnombre() << endl;
                    cout << "Total de la venta: S/ " << precio * cantidadVender << endl;

                    //registrar ventas array:
                    ventas[cantidad_ventas]= new RegistroVenta{id, producto->getnombre(), cantidadVender, venta_ini};
                    cantidad_ventas++;
                } else {
                    cout << "No hay suficiente stock para la venta." << endl;
                }
            } else {
                cout << "Producto no encontrado." << endl;
            }
        }
    
        void mostrarVentas() {
            for (int i=0; i<cantidad_ventas; i++){
                cout<<".: VENTA"<< i+1<<" :."<<endl;
                cout<<"id: "<<ventas[i]->idProducto<<endl;
                cout<<"nombre: "<<ventas[i]->nombreProducto<<endl;
                cout<<"cantidad vendida: "<<ventas[i]->cantidadVendida<<endl;
                cout<<"venta: "<<ventas[i]->totalVenta<<endl;
            }
            cout << "\nTotal de ventas realizadas: S/ " << totalVenta << endl;
        }
        ~Venta() {
            cout << "VENTAS destruidas "  << endl;
        }
};


struct RegistroPedido {
    string id_pedido;
    string nombre_cliente;
    string idProducto;
    string nombreProducto;
    int cantidadVendida;
    float Venta;
    string estado;
};
       
class Pedido {
    private:
        Venta* ventas;
        RegistroPedido* pedidos[10];
        Inventario* inventario;
        string id_pedido, nombre_cliente;
        int cantidad_pedido;
        int n;
        
    public:
    
        Pedido(Inventario& inv){
            inventario = &inv; 
            id_pedido = " "; 
            cantidad_pedido=0;
            n=0;
        }

        void registrar_pedido(string id_pedido, string nombre_cliente, string id, int cantidad_pedido ){
            if (n>10){
                cout<<"lista llena [10]"<<endl;
                return;
            }
            Producto* producto= inventario->obtenerProducto(id);
            float venta= (producto->getprecio())*cantidad_pedido;
            pedidos[n]= new RegistroPedido{id_pedido,nombre_cliente,id, producto->getnombre(), cantidad_pedido, venta, "pendiente"};
            n++;
        }

        void imprimir_pedidos_pendientes(){
            for (int i=0; i<n; i++){
                if (pedidos[i]->estado=="pendiente"){
                    cout<<endl;
                    cout<<"\n-------------------------------------------------"<<endl;
                
                    cout<<".:PEDIDO "<<pedidos[i]->id_pedido<<":."<<endl;
                    cout<<"nombre del cliente: "<<pedidos[i]->nombre_cliente<<endl;
                    cout<<"nombre del producto: "<<pedidos[i]->nombreProducto<<endl;
                    cout<<"cantidad solicitada: "<<pedidos[i]->cantidadVendida<<endl;
                    cout<<"total de la venta: "<<pedidos[i]->Venta<<endl;
            
                    cout<<"\n-------------------------------------------------"<<endl;
                }
            }
        }

        void actualizar_pedidos(string id_pedido){
            for (int i=0; i<n; i++){
                if (pedidos[i]->id_pedido==id_pedido){
                    pedidos[i]->estado="completado";
                    cout<<"pedido actualizado a COMPLETADO..."<<endl;
                    return;
                }
            }
            cout<<"el id del pedido no se encuentra como pendiente o no esta resgistarado..."<<endl;
        }


        void notificar_cliente(string id){
            for (int i=0; i<n; i++){
                if (pedidos[i]->id_pedido==id and  pedidos[i]->estado=="completado" ){
                    cout<<pedidos[i]->nombre_cliente<< "su pedido está listo..."<<endl;
                    Producto* producto= inventario->obtenerProducto(pedidos[i]->idProducto);
                    producto->setCantidadStock(producto->getCantidadStock() - pedidos[i]->cantidadVendida);
                    cout<<"\nSe actualizo el stock"<<endl;
                    ventas->set_venta_total(ventas->get_venta_total()+ pedidos[i]->Venta);
                    return;
                }
            }
            cout<<"el id del pedido no se encuentra como completado o no esta resgistarado..."<<endl;
        }

        ~Pedido() {
            cout << "pedidos destruidos" << endl;
        }


};


void MenuPrincipal(){
    cout <<"\t==== SISTEMA DE TIENDA DE ABARROTES ===="<<endl;
    cout <<"1. Gestion de Inventario"<<endl;
    cout <<"2. Registro de Ventas"<<endl;
    cout <<"3. Gestion de Pedidos"<<endl;
    cout <<"4. Reportes"<<endl;
    cout <<"5. salir"<<endl;
}

void menuInventario(){
    cout <<"\t==== GESTION DE INVENTARIO ===="<<endl;
    cout <<"1. Agregar producto"<<endl;
    cout <<"2. Eliminar producto"<<endl;
    cout <<"3. Actualizar stock"<<endl;;
    cout <<"4. Volver al menu principal"<<endl;
}

void menuPedidos(){
    cout <<"\t==== GESTIÓN DE PEDIDOS ===="<<endl;
    cout <<"1. Registrar nuevo pedido"<<endl;
    cout <<"2. Actualizar estado de pedido"<<endl;
    cout <<"3. Notificar cliente"<<endl;
    cout <<"4. Volver al menu principal"<<endl;
}

void menuReportes(){
    cout <<"\t==== REPORTES ===="<<endl;
    cout <<"1. Reporte de Ventas"<<endl;
    cout <<"2. Reporte de Inventario"<<endl;
    cout <<"3. Reporte de pedidos pendientes"<<endl;
    cout <<"4. Volver al menu principal"<<endl;
}

int main(){
    Inventario tienda;
    Venta ventas(tienda);
    Pedido pedidos(tienda);

    while (true){
        string nombre,id;
        float precio;
        int cantidadstc;
        int op;
        MenuPrincipal();
        cout<<"\n opcion: "; 
        cin>>op;

        if (op==1){
            int opcion1;
            while (true){
                
                menuInventario();
                cout<<"\n opcion: "; 
                cin>>opcion1;
                if (opcion1==1){
                    cout<< "ingrese el ID del producto: "; cin>>id;
                    cout<< "ingrese el nombre del producto: "; cin>>nombre;
                    cout<<"ingrese el precio: ";cin>>precio;
                    cout<<"cantidad en stock: "; cin>>cantidadstc;
                    tienda.agregar_producto(id, nombre,precio, cantidadstc );
                   
                }
                else if (opcion1==2){
                    cout<< "ingrese el ID del producto: "; cin>>id;
                    tienda.eliminar_producto(id);
                }
                else if (opcion1==3){
                    int nueva_can;
                    cout<< "ingrese el ID del producto: "; cin>>id;
                    cout<<"nueva cantidad: "; cin>>nueva_can;
                    tienda.actualizar_stock(id, nueva_can);
                }
                else{
                    break;
                }

            }
        }
        else if (op==2){
            int cantidad_vender;
            cout<<endl;
            cout<<"ingrese ID de producto a vender: ";cin>>id;
            cout<<"ingrese cantidad: "; cin>>cantidad_vender;
            ventas.registrarVenta(id, cantidad_vender);
        
        }
        else if (op==3){
            int opc;
            while (true){
                menuPedidos();
                string nombre_per,id_pedido;
                int cant_pedida;
              
                cout<<"\n opcion: "; 
                cin>>opc;
                if (opc==1){
                    cout<<"\n id del pedido: "; cin>>id_pedido;
                    cout<<"\n Ingrese nombre del cliente: "; cin>>nombre_per;
                    cout<<"ID del producto: "; cin>>id;
                    cout<<"ingrese cantidad: "; cin>>cant_pedida;
                    pedidos.registrar_pedido(id_pedido,nombre_per, id, cant_pedida);
                }
                else if (opc==2){
                    cout<<"\nid del pedido a ACTUALIZAR: "; cin>>id_pedido;
                    pedidos.actualizar_pedidos(id_pedido);
                }
                else if (opc==3){
                    cout<<"\nid del pedido a NOTIFICAR: "; cin>>id_pedido;
                    pedidos.notificar_cliente(id_pedido);
                }
                else if (opc==4){
                    break;
                }
            }
        }
        else if (op==4){
            int opcion1;
            while (true){
                menuReportes();
                cout<<"\n opcion: "; 
                cin>>opcion1;
                if (opcion1==1){
                    ventas.mostrarVentas();
                }
                else if (opcion1==2){
                    tienda.mostrar_stock();
                }
                else if (opcion1==3){
                    pedidos.imprimir_pedidos_pendientes();
                }
                else if (opcion1==4){
                    break;
                }
                else{
                    cout<<"opcion invalida"<<endl;
                }
            }
        }
        else if (op==5){
            break;

        }
        else {
            cout<<"opcion invalida..."<<endl;

        }
    }
    return 0;
}