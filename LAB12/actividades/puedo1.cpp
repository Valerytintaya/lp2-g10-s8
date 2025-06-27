#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Producto{
    protected:

    string des;
    int cantidad;
    
    public:
    Producto(string d, int c): des(d), cantidad(c){}
    
    int getCantidad(){return cantidad;}
    void setCantidad(int nuevo){cantidad=nuevo;}

    void mostrar(){
        cout<<"==PRODUCTO=="<<endl;
        cout<<"descripcion: "<<des
            <<"cantidad: "<<cantidad<<endl;
    }
};

class Inventario{
    protected:
    map <string,set <Producto> producto> productos;
    
    public:
    
    void agregar(string codigo,Producto p){
        productos[codigo]=p;
        cout<<"producto agregado"<<endl;
    }
    
    void actualizar(string codigo, int nueva){
        try {
            Producto p = productos.at(codigo);
            p.setCantidad(nueva);
            cout<<"cantidad actulizada"<<endl;

        } catch (const out_of_range& e) {
        cout << "Clave no encontrada." << endl;
        }
    }

    Producto bucarCodigo(string codigo){
        try {
            Producto p = productos.at(codigo);
            cout<<"Producto encontrado"<<endl;
            p.mostrar();

        } catch (const out_of_range& e) {
        cout << "Producto no encontrada." << endl;
        }
    }
};
int main(){
    
    return 0;
}
