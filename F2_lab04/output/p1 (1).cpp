#include <iostream>
#include <string>
using namespace std;
class Producto {
    private:
    string nombre;
    float precio, descuento;
    
    public:
    Producto (){
        nombre = "anonimo";
        precio=0;
        descuento = 0;
    }
    
    Producto (string n, float p, float des): nombre (n), precio(p), descuento(des){
        cout<<"objeto creado.."<<endl;
    }
    
     // Establecer nombre con autoreferencia
    Producto& setNombre(const string& nombre) {
        this->nombre = nombre; // this->nombre se refiere al atributo, nombre es el parámetro
        return *this; // devuelve referencia al objeto actual
    }

    // Establecer precio con autoreferencia
    Producto& setPrecio(float precio) {
        this->precio = precio;
        return *this;
    }
    
    // Establecer descuento con autoreferencia
    Producto& setDescuento(float des) {
        this->descuento = des;
        return *this;
    }
    
    void mostrar (){
        cout<<"nombre: "<<nombre <<" | precio : "<<precio << " | descuento: "<<descuento<<endl;
    }
    
    float PrecioFinal (){
        return precio * ((100.0-descuento)/100);
    }

    
};

int main (){
    float montofinal=0;
    Producto productos [3]={
        Producto ("auto", 250, 50),
        Producto ("moto", 500, 30),
        Producto ("bicicleta", 120, 15)
    };
    
    productos[0].setNombre("Camion").setPrecio(1000).setDescuento(50);
    
    for (int i= 0; i<3; i++ ){
        productos[i].mostrar();
        montofinal+= productos[i].PrecioFinal();
    }
    
    cout <<"---------------------------"<<endl;
    cout<<"monto final: "<<montofinal;
    
    return 0;
}