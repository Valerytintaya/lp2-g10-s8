#include <iostream>
#include <string>
using namespace std;
const int maxi=10;

class Asignatura ;
class Nota;
class Asistencia;

class Estudiante{
    public:
    string nombre, direc, matri;
    Asignatura* asigs[maxi];
    Nota* nota[maxi];
    Asistencia* asisten [maxi];
    int numAsig, numNota, numAsiste;

    Estudiante (string n, string d, string m) : nombre(n), direc(d), matri(m), numAsig(0),numNota(0), numAsiste(0) {}
    void agregarAsignatura(Asignatura* nueva){
        if (numAsig<maxi){
            asigs[numAsig++]= nueva;
            cout<<"agregado exitosamente.."<<endl;
        }
    }

    void agregarNota(Nota* n){
        if (numNota<maxi){
            nota[numNota++]= n;
            cout<<"agregado exitosamente.."<<endl;
        }
    }

    void agregarAsistencia(Asistencia* asis){
        if (numAsiste<maxi){
            asisten[numAsiste++]= asis;
            cout<<"agregado exitosamente.."<<endl;
        }
    }

    void mostrarAsigEstu();

    void mostrarResumen();

};



class Profesor {
    public:
    string nombre, direc, telefono;
    Asignatura* asigs[maxi];
    int numAsig;

    Profesor (string n, string d, string t) : nombre(n), direc(d), telefono(t), numAsig(0) {}

    void agregarAsignatura(Asignatura* nueva){
        if (numAsig<maxi){
            asigs[numAsig++] = nueva;
            cout<<"agregado exitosamente.."<<endl;
        }
    }

    void mostrarAsignaturas() ;

    void mostrarProfesor(){
        cout<< " - "<< nombre << " - "<< telefono<<endl;
    }

};


class Asignatura {
    public:
    string codigo,nombre, descrip;
    Profesor* profesor;
   
    Asignatura (string c, string n , string m, Profesor* p) : codigo(c), nombre(n), descrip(m), profesor(p) {}

    void mostrarinfo(){
        cout << "Codigo: " << codigo << ", Nombre: " << nombre << " - "<< descrip
             << ", Profesor: " << profesor->nombre << endl;
    }
};
class Nota {
    public:
    float nota;
    Estudiante* es;
    Asignatura* asig;
    Nota(float n, Asignatura* a): nota(n), asig(a){}
    void mostrar() {
        cout << "Asignatura: " << asig->nombre << " Nota: " << nota << endl;
    }
};
class Asistencia {
    public:
    string fecha;
    bool presente;
    Estudiante* estu;
    Asignatura* asig;
    Asistencia(string f, bool p, Asignatura* a) : fecha(f), presente(p), asig(a) {}

    void mostrar() {
        cout << "Fecha: " << fecha << " - " << asig->nombre
             << " - " << (presente ? "Presente" : "Ausente") << endl;
    }
};




void Estudiante :: mostrarResumen (){
    cout << "Estudiante: " << nombre << ", Matricula: " << matri << endl;
    cout << "Asignaturas:\n";
    for (int i = 0; i < numAsig; i++) asigs[i]->mostrarinfo();
    cout << "Notas:\n";
    for (int i = 0; i < numNota; i++) nota[i]->mostrar();
    cout << "Asistencias:\n";
    for (int i = 0; i < numAsiste; i++) asisten[i]->mostrar();

}


void Profesor:: mostrarAsignaturas(){
    cout << "Asignaturas de " << nombre << ":\n";
        for (int i = 0; i < numAsig; i++) {
            asigs[i]->mostrarinfo();
        }
}

void Estudiante:: mostrarAsigEstu(){
    for (int i=0; i<numAsig; i++){
        cout<< i+1<< " |";
        asigs[i]->mostrarinfo();
    }
}


int main() {
    Estudiante* estudiantes[maxi]; int numEst = 0;
    Profesor* profesores[maxi]; int numProf = 0;
    Asignatura* asignaturas[maxi]; int numAsig = 0;
    int numMa=0;
 
    int opcion;
    int num;

    do {
        cout << "\n--- MENU UNIVERSIDAD ---\n";
        cout << "1. Registrar Estudiante\n";
        cout<<  "2. Registrar Profesor\n";
        cout<<  "3. Registrar Asignatura\n";
        cout << "4. Matricular Estudiante\n";
        cout<<  "5. Registrar Nota\n";
        cout<<  "6. Registrar Asistencia\n";
        cout << "7. Mostrar Estudiantes\n";
        cout<<  "0. Salir\n";
        cout<<  "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string n, d, m;
                cout<<"numero de estudiantes a agregar: ";
                cin>>num;
                for (int i=0; i<num; i++){
                    cout << "Nombre: "; cin >> n;
                    cout << "Direccion: "; cin >> d;
                    cout << "Matricula: "; cin >> m;
                    estudiantes[numEst++] = new Estudiante(n, d, m);
                }
                break;
            }
            case 2: {
                string n, d, t;
                cout<<"numero de profesores a agregar: ";
                cin>>num;

                for (int i=0; i<num; i++){
                    cout << "Nombre: "; cin >> n;
                    cout << "Direccion: "; cin >> d;
                    cout << "Telefono: "; cin >> t;
                    profesores[numProf++] = new Profesor(n, d, t);
                }
                break;
            }
            case 3: {
                string c, n, d;
                if (numProf==0){
                    cout<<"primero registre profesores"<<endl;
                    break;
                }
                
                cout<<"numero de profesores a agregar: ";
                cin>>num;

                for (int i=0; i<num; i++){
                    int ind;
                    cout << "Codigo: "; cin >> c;
                    cout << "Nombre: "; cin >> n;
                    cout << "Descripcion: "; cin >> d;
                    cout<< endl;
                    cout<<"===PROFESORES==="<<endl;

                    for (int j = 0; j < numProf; j++){
                        cout << j + 1 << " | " ;
                        profesores[j]->mostrarProfesor();
                    }

                    cout << "Profesor (indice):\n"; cin >> ind;
                    Profesor* p= profesores[ind-1];
                    asignaturas[numAsig] = new Asignatura(c, n, d, p);
                    profesores[ind-1]->agregarAsignatura(asignaturas[numAsig]);
                    numAsig++;
                }
                break;
            }
            case 4: {
                if (numAsig==0 || numEst==0){
                    cout<<"primero registre estudiantes / asignaturas"<<endl;
                    break;
                }
                int est, asig;
                cout<<"\n===ESTUDIANTES==="<<endl;
                for (int i = 0; i < numEst; i++)
                    cout << i + 1 << " | " << estudiantes[i]->nombre << endl;
                
                cout << "Estudiante (indice):\n";
                cin >> est;
                

                cout<<"\n===ASIGNATURAS==="<<endl;
                for (int i = 0; i < numAsig; i++){
                    cout << i + 1 << "| " ;
                    asignaturas[i]->mostrarinfo();
                }

                cout << "Asignatura (indice):\n";
                cin >> asig; 
                estudiantes[est-1]->agregarAsignatura(asignaturas[asig-1]);
                numMa++;
                break;
            }

            case 5: {
                if (numMa==0){
                    cout<<"primero matricule algun estudiante..."<<endl;
                    break;
                }
                int est, asig;
                float nota;

                cout<<"\n===ESTUDIANTES==="<<endl;
                for (int i = 0; i < numEst; i++)
                    cout << i + 1 << " | " << estudiantes[i]->nombre << endl;
                
                cout << "Estudiante (indice):\n";
                cin >> est;



                cout<<"\n===ASIGNATURAS==="<<endl;
                estudiantes[est-1]->mostrarAsigEstu();

                cout << "Asignatura (indice):\n";
                cin >> asig; 

                cout << "Nota: "; cin >> nota;

                Asignatura* a = estudiantes[est-1]->asigs[asig-1];
                estudiantes[est-1]->agregarNota(new Nota(nota, a));
                break;
            }

            case 6: {
                if (numMa==0){
                    cout<<"primero matricule algun estudiante..."<<endl;
                    break;
                }
                int est, asig;
                string fecha;
                char pres;
                
                cout<<"\n===ESTUDIANTES==="<<endl;
                for (int i = 0; i < numEst; i++)
                    cout << i + 1 << " | " << estudiantes[i]->nombre << endl;
                
                cout << "Estudiante (indice):\n";
                cin >> est;

                cout<<"\n===ASIGNATURAS==="<<endl;
                estudiantes[est-1]->mostrarAsigEstu();

                cout << "Asignatura (indice):\n";
                cin >> asig; 

                cout << "Fecha: "; cin >> fecha;
                cout << "Presente (s/n): "; cin >> pres;
                Asignatura* a = estudiantes[est-1]->asigs[asig-1];
                estudiantes[est-1]->agregarAsistencia(new Asistencia(fecha, pres == 's', a));
                break;
            }
            case 7: {
                for (int i = 0; i < numEst; i++) {
                    estudiantes[i]->mostrarResumen();
                    cout << endl;
                }
                break;
            }
        }
    } while (opcion != 0);

    return 0;
}
