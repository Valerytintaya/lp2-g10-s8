#include <iostream>
#include <string>
using namespace std;

class Movil{
    private:
    string marca, modelo, sistema; 
    
    public:
    Movil(string ma, string mo, string s ) : marca (ma), modelo(mo), sistema(s) {
        cout<< "movil creado.."<<endl;
    }
    
    void mostrar(){
        cout<< "marca: "<< marca << " | modelo: "<<modelo << " | sistema: "<< sistema << endl; 
    }
    
    string getModelo(){return modelo;}
    ~ Movil() {
        cout<< "se eliminó objeto MOVIL: "<< modelo << endl;
    }
};

class Telefono: public Movil{
    private:
    string color;
    
    public:
    Telefono(string ma, string mo, string s, string c) :
    Movil(ma, mo, s), color(c) {
        cout << "telefono creado  "<<endl;
    }
    
    
    void mostrarTelefono(){
        mostrar();
        cout<< "color: "<< color  << endl; 
    }
    
    ~ Telefono(){
        cout<< "se eliminó objeto TELEFONO: "<< getModelo() << endl;
    }
};

class Tablet: public Movil {
    private:
    string memoria;
    
    public:
    Tablet(string ma, string mo, string s, string me) :
    Movil(ma, mo, s), memoria(me) {
        cout << "tablet creada ... "<<endl;
    }
    
    
    void mostrarTablet(){
        mostrar();
        cout<< "memoria: "<< memoria  << endl; 
    }
    
    
    ~ Tablet(){
        cout<< "se eliminó objeto TABLET: "<< getModelo() << endl;
    }
};

int main() {
     // Crear un objeto Telefono
    Telefono telefono1("Samsung", "Galaxy S21", "Android", "Negro");

    // Crear un objeto Tablet
    Tablet tablet1("Apple", "iPad Pro", "iOS", "256GB");

    // Los objetos se destruyen automáticamente
    return 0;
}
