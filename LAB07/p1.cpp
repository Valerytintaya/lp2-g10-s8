#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
    protected:
    string marca, modelo, anio;
    float precio;
    
    public:
    Vehiculo(string m, string mo, string a, float p) 
    :marca(m), modelo(mo), anio(a), precio(p) {}
    
    void mostrar(){
        cout<< "marca : "<<marca << " | modelo: "<<modelo 
            <<" | anio fabricación: "<< anio << " | precio: "<< precio << endl;
    }
    
};
class Automovil: public Vehiculo{
    private:
    int num_puertas;
    string tipo;
    
    public:
    
    Automovil(string m, string mo, string a, float p, int n, string t) 
    : Vehiculo (m,mo,a,p), num_puertas(n), tipo(t) {}
    
    void mostrarAuto(){
        mostrar ();
        cout << "numero de puertas: "<< num_puertas << endl;
        cout << "tipo de combustible: "<< tipo << endl;
    }
    
};
class Moto: public Vehiculo{
    private:
    float cilindrada;
    
    public:
    
    Moto(string m, string mo, string a, float p, int c) 
    : Vehiculo (m,mo,a,p), cilindrada(c) {}
    
     void mostrarMoto(){
        mostrar ();
        cout << "cilindrada: "<< cilindrada << endl;
    }
};
int main(){
    Automovil a1("Toyota", "Corolla", "2022", 25000, 4, "gasolina");
    Moto m1("Honda", "CBR500R", "2023", 6500, 500);
    
    // Mostrar la información de los vehículos
    cout << "Información del automóvil:" << endl;
    a1.mostrarAuto();  
    
    cout << "\nInformación de la moto:" << endl;
    m1.mostrarMoto();  
    return 0;
}
