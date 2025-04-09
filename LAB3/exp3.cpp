#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Profesor {
public:
    string nombre;
    Profesor(string nombre) : nombre(nombre) {}
    ~Profesor (){
        cout<<"se elimino profesor..."<<endl;
    }
};
class Estudiante {
public:
    string nombre;
    Estudiante(string nombre) : nombre(nombre) {}
    ~Estudiante(){
        cout<<"se elimino es..."<<endl;
    }
};
class Curso {
public:
    string nombre;
    Curso(string nombre) : nombre(nombre) {}
    ~Curso (){
        cout<<"se elimino curso..."<<endl;
    }
};

// Clase intermedia para modelar la asociación ternaria
class Asociacion {
public:
    Estudiante* estudiante;
    Curso* curso;
    Profesor* profesor;

    Asociacion(Estudiante* est, Curso* cur, Profesor* prof)
        : estudiante(est), curso(cur), profesor(prof) {}

    void mostrarInformacion() {
        cout << estudiante->nombre << " esta inscrito en " << curso->nombre
             << " con el profesor " << profesor->nombre << "." << endl;
    }

    ~Asociacion (){
        cout<<"se elimino asociacion..."<<endl;
    }
};

int main() {
    Profesor prof("Dr. Lopez");
    Estudiante est("Juan Perez");
    Curso curso("Programacion Avanzada");

    Profesor p1("Dr. Carlos");
    Estudiante e1("Diego");
    Curso c1("calculo");


    Asociacion aso(&est, &curso, &prof);
    Asociacion aso1(&est, &c1, &p1);
    Asociacion aso2(&e1, &curso, &prof);

    aso.mostrarInformacion();
    aso1.mostrarInformacion();
    aso2.mostrarInformacion();

    return 0;
}
