#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Persona{
    protected:
    string nombre;
    int edad;
    string dire;

    public:
    Persona(string n, int e, string d): nombre(n), edad(e), dire(d) {}
    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setDireccion(string d) { dire = d; }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getDireccion() const { return dire; }

};

int main(){
    Persona p1("ana", 14, "ninguno");
    ofstream archivo;

    archivo.open("panas.txt", ios::app);

    archivo<<p1.getNombre()<<"-";
    archivo<<p1.getEdad()<<endl;
    archivo<<p1.getDireccion()<<endl;

    archivo.close();

    return 0;
}

