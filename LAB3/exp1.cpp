#include <iostream>
#include <vector>
#include <string>
using namespace std;
// asocaiocnes UNIDIRECCIONALES
class Hijo{
    private:
    string nombre;

    public:
    //constructor
    Hijo(string n= " " ): nombre(n) {}
    
    void setNombre(string nuevo){nombre= nuevo;}
    string getNombre(){return nombre;}
}; 

class Padre{
    private:
    string nombre;
    Hijo hijos[10];
    int numHijos;

    public:
    //constructor
    Padre(string n= " " ): nombre(n), numHijos(0) {}

    void setNombre(string nuevo){nombre= nuevo;}
    string getNombre(){return nombre;}

    //recibe objeto hijo
    void agregarHijo(Hijo& nuevohijo){
        if (numHijos<10)
            hijos[numHijos++]=nuevohijo;
        else 
            cout<<"se paso la cantidad de hijos"<<endl;
    }

    void ImprimirHijos(){
        cout << "Hijos de " << nombre << ":" << endl;
        cout<<"hijos en total : "<< numHijos<<endl;
        for (int i = 0; i < numHijos; i++) {
            cout << "- " << hijos[i].getNombre() << endl;
        }
    }
};

int main(){
    Padre p("juan");
    Hijo h("antonio");
    Hijo hi("luis");
    Hijo c("carlos");
    Hijo a("angel");

    p.agregarHijo(h);
    p.agregarHijo(hi);
    p.agregarHijo(c);
    p.agregarHijo(a);

    p.ImprimirHijos();
}
