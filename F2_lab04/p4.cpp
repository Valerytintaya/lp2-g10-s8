#include <iostream>
#include <string>
using namespace std;

class Gerente{
    private:
    string nombre, dni;
    
    public:
    Gerente(){
        nombre="anonimo";
        dni="12345678";
        cout<<"se creo objeto gerente... "<<endl;
    }

    Gerente(string n, string d) : nombre(n), dni(d) {
        cout<<"se creo objeto gerente... "<<endl;
        mostrar();
          
    }

    void mostrar(){
        cout<<"GERENTE - nombre: "<<nombre<<" | dni: "<<dni<<endl;
    }

    ~Gerente(){
        cout<< "se destruye gerente: "<<nombre<<endl;
    }

};

class Direccion {
    private:
        string ciudad;
        string calle;
    
    public:
        // Constructor de Direccion
        Direccion(string _ciudad, string _calle) {
            ciudad = _ciudad;
            calle = _calle;
            cout<<"se creo objeto direccion... "<<endl;
            mostrarDireccion();
        }
    
        // Métodos de acceso
        string getCiudad() { return ciudad; }
        string getCalle() { return calle; }
    
        // Método para mostrar información de la dirección
        void mostrarDireccion() {
            cout << "DIRECCION - Ciudad: " << ciudad << " | Calle: " << calle << endl;
        }

        ~Direccion(){
            cout<< "se destruye direccion  "<<endl;
        }
};

class Empresa{
    private:
    string nombre, ruc;
    Gerente gerente;
    Direccion direccion;

    public:
    Empresa(string n, string r,string nom, string d, string _ciudad, string _calle)
    : nombre(n), ruc(r), gerente(nom, d), direccion(_ciudad, _calle)   {
        cout<<"se creo objeto empresa... "<<endl;
        mostrar();
    }

    void mostrar(){
        cout<< nombre <<" | "<< ruc<<endl;
    }

    ~Empresa(){
        cout<< "se destruye empresa: "<<nombre<<endl;
    }
};

int main(){
    Empresa miEmpresa("TechSoluciones", "20481234567", "Laura Diaz", "40321234", "Arequipa", "Av. Kennedy 123");
    return 0;
}