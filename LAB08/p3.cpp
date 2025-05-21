#include <iostream>
#include <string>
using namespace std;

class Empleado{
    protected:
    string nombre;
    public:
    Empleado(string n): nombre(n){}
    virtual float calcularSalario() = 0;
    virtual void mostrar()=0;

    virtual ~Empleado(){};
};

class EmpleadoCompleto: public Empleado{  
    private:
    float mensual;

    public:
    EmpleadoCompleto(string n, float m): Empleado(n), mensual(m){}

    float calcularSalario() override{
        return mensual;
    }

    void mostrar(){
        cout<<"nombre: "<< nombre <<" | sueldo mensual: "<< mensual<<endl;
    }
};
class EmpleadoMedio: public Empleado{
    private:
    int horas;
    float pagoHora;

    public:
    EmpleadoMedio(string n, int h, float p): Empleado(n), horas(h), pagoHora(p) {}

    float calcularSalario() override{
        return horas* pagoHora;
    }
    void mostrar(){
        cout<<"nombre: "<< nombre <<" | horas: "<< horas<< " | pago * hora: "<<pagoHora<<endl;
    }

};
int main(){
    Empleado* e1= new EmpleadoCompleto("marta", 1000);
    Empleado* e2= new EmpleadoMedio("marta", 10, 20);

    cout<<"empleado completo: "<<e1->calcularSalario()<<endl;
    cout<<"empleado medio tiempo: "<<e2->calcularSalario()<<endl;

    delete e1;
    delete e2;
    return 0;
}