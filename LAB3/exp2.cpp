#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Curso;
//  BIDIRECCIONALES
class Estudiante{
    private:
    string nombre, apellido, identificacion, correo;
    Curso* cursos[10];
    int numCursos;

    public:
    //constructor
    Estudiante(string n= " ",string a= " ", string d= " ", string co=" ")
    : nombre(n), apellido(a), identificacion(d), correo(co), numCursos(0) {}

    void setIdentificacion(string nuevo){identificacion= nuevo;}
    string getIdentidad(){return nombre;}

    //agregar curso
    void agregarCurso(Curso* nuevoCurso) {
        if (numCursos < 10) {
            cursos[numCursos++] = nuevoCurso;
        } else {
            cout << "No se puede agregar más cursos al estudiante." << endl;
        }
    }

    void eliminarCurso(Curso* cursoAEliminar) {
        for (int i = 0; i < numCursos; ++i) {
            if (cursos[i] == cursoAEliminar) {
                for (int j = i; j < numCursos - 1; ++j) {
                    cursos[j] = cursos[j + 1];
                }
                numCursos--;
                cout << "Curso eliminado del estudiante." << endl;
                return;
            }
        }
        cout << "Curso no encontrado en la lista del estudiante." << endl;
    }

    void imprimirCur(){
        cout<<"Curso de : "<<nombre<<endl;
        for (int i=0; i<numCursos; i++){
            cout<<"-"<<cursos[i]->getNombre()<<endl;
        }
    }
}; 

class Curso{
    private:
    string nombre, codigo, descripcion, fechaInicio, fechaFinal;
    Estudiante* estudiantes[10];
    int num;

    public:

    Curso(string n= " ",string c= " ", string d= " ", string ini=" ", string fi=" ")
    : nombre(n), codigo(c), descripcion(d), fechaInicio(ini), fechaFinal(fi), num(0) {}

    string getNombre(){return nombre;}

    void agregarEstudiante(Estudiante* nuevo){
        if (num<10){
            estudiantes[num++]=nuevo;
            nuevo->agregarCurso(this);
        }
        else 
            cout<<"se paso la cantidad de estudiantes"<<endl;
    }

    void EliminarEstudiante(Estudiante* nuevo){
        for (int i=0; i<num; i++){
            if (nuevo==estudiantes[i]){
                for (int j=i; j<num-1; j++){
                    estudiantes[j]=estudiantes[j+1];
                }
                num--;
                nuevo->eliminarCurso(this);
                cout<<"completado exitosamente..."<<endl;
                return;
            }
        }
        cout<<"no se encontro el curso"<<endl;
    }

    void imprimirEs(){
        cout<<"Estudiantes en : "<<nombre<<endl;
        for (int i=0; i<num; i++){
            cout<<"-"<<estudiantes[i]->getIdentidad()<<endl;
        }
    }

};


int main(){
    Curso c1("matematica");
    Curso c2("ciencia");

    Estudiante e1("carlos", "xxxx", "12345", "xxxx");
    Estudiante e2("bety", "xxx1", "10034", "xxx2");
    Estudiante e3("emy", "xx2x", "11145", "xx13");

    c1.agregarEstudiante(&e1);
    c1.agregarEstudiante(&e2);
    c1.agregarEstudiante(&e3);

    c2.agregarEstudiante(&e3);
    c2.agregarEstudiante(&e2);

    c1.imprimirEs();
    c2.imprimirEs();

    e1.imprimirCur();
    e3.imprimirCur();

}