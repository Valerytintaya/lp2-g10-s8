#include <iostream>
#include <string>

using namespace std;

// Interfaces esenciales
class IMostrable {
public:
    virtual void mostrar() const = 0;
    virtual ~IMostrable() {}
};

class IActualizable {
public:
    virtual void actualizarEstado(const string& nuevoEstado) = 0;
    virtual ~IActualizable() {}
};

// Implementación de Estado
class EstadoTarea {
private:
    string estado;
public: 
    EstadoTarea(string e = "pendiente") : estado(e) {}

    void setEstado(const string& nuevo) {
        estado = nuevo;
    }

    string getEstado() const { return estado; }
};

// Clase base Tarea
class Tarea : public IMostrable, public IActualizable {
protected:
    string titulo;
    string fechaLimite;
    string usuarioAsignado;
    EstadoTarea estado;

public:
    Tarea(string t, string f, string u, string e = "pendiente")
        : titulo(t), fechaLimite(f), usuarioAsignado(u), estado(e) {}

    void actualizarEstado(const string& nuevoEstado) override {
        estado.setEstado(nuevoEstado);
    }

    void mostrar() const override {
        cout << "Tarea: " << titulo 
             << " | Fecha: " << fechaLimite
             << " | Asignado: " << usuarioAsignado  
             << " | Estado: " << estado.getEstado();
    }

    string getTitulo() const { return titulo; }
    string getFecha() const { return fechaLimite; }
};

// Tipos especializados de tareas
class TareaGeneral : public Tarea {
public:
    TareaGeneral(string t, string f, string u, string e = "pendiente")
        : Tarea(t, f, u, e) {}

    void mostrar() const override {
        Tarea::mostrar();
        cout << " | Tipo: General";
    }
};

class TareaUrgente : public Tarea {
private:
    int nivelUrgencia;
public:
    TareaUrgente(string t, string f, string u, int urgencia, string e = "pendiente")
        : Tarea(t, f, u, e), nivelUrgencia(urgencia) {}

    void mostrar() const override {
        Tarea::mostrar();
        cout << " | Urgencia: " << nivelUrgencia << " | Tipo: Urgente";
    }
};

// Gestor de tareas
class IGestorTareas {
public:
    virtual void agregarTarea(Tarea* tarea) = 0;
    virtual void listarTareas() const = 0;
    virtual void actualizarEstadoTarea(int indice, const string& nuevoEstado) = 0;
    virtual ~IGestorTareas() {}
};

class GestorTareas : public IGestorTareas {
private:
    static const int MAX_TAREAS = 10;
    Tarea* tareas[MAX_TAREAS];
    int cantidad;

public:
    GestorTareas() : cantidad(0) {}

    void agregarTarea(Tarea* t) override {
        if (cantidad < MAX_TAREAS) {
            tareas[cantidad++] = t;
        } else {
            cout << "Error: No se pueden agregar más tareas.\n";
        }
    }

    void listarTareas() const override {
        if (cantidad == 0) {
            cout << "\nNo hay tareas registradas.\n";
            return;
        }
        
        cout << "\n--- LISTADO DE TAREAS ---\n";
        for (int i = 0; i < cantidad; i++) {
            cout << i+1 << ". ";
            tareas[i]->mostrar();
            cout << endl;
        }
    }

    void actualizarEstadoTarea(int indice, const string& nuevoEstado) override {
        if (indice >= 0 && indice < cantidad) {
            tareas[indice]->actualizarEstado(nuevoEstado);
            cout << "Estado actualizado correctamente.\n";
        } else {
            cout << "Error: Número de tarea inválido.\n";
        }
    }

};


class Proyecto : public IMostrable {
    private:
        string nombre;
        string comentarios[10];
        string archivosCompartidos[10];
        int numComentarios;
        int numArchivos;
    
    public:
    Proyecto() : nombre(""), numComentarios(0), numArchivos(0) {} // Constructor por defecto
    Proyecto(string n) : nombre(n), numComentarios(0), numArchivos(0) {}

        void agregarComentario(const string& comentario) {
            if (numComentarios < 10) {
                comentarios[numComentarios++] = comentario;
            } else {
                cout << "No se pueden agregar más comentarios.\n";
            }
        }
    
        void compartirArchivo(const string& archivo) {
            if (numArchivos < 10) {
                archivosCompartidos[numArchivos++] = archivo;
            } else {
                cout << "No se pueden compartir más archivos.\n";
            }
        }
    
        void mostrar() const override {
            cout << "\n--- Proyecto: " << nombre << " ---\n";
            cout << "Comentarios:\n";
            for (int i = 0; i < numComentarios; i++) {
                cout << "- " << comentarios[i] << "\n";
            }
            cout << "Archivos Compartidos:\n";
            for (int i = 0; i < numArchivos; i++) {
                cout << "- " << archivosCompartidos[i] << "\n";
            }
        }
    };
const int max=10;
// Función principal interactiva
int main() {
    GestorTareas gestor;
    Proyecto proyectos[10];
    int numProyectos = 0;
    int opcion;

    do {
        cout << "\n--- MENU DE GESTION DE TAREAS ---\n";
        cout << "1. Agregar tarea general\n";
        cout << "2. Agregar tarea urgente\n";
        cout << "3. Listar todas las tareas\n";
        cout << "4. Actualizar estado de tarea\n";
        cout << "5. Crear nuevo proyecto\n";
        cout << "6. Agregar comentario a un proyecto\n";
        cout << "7. Compartir archivo en un proyecto\n";
        cout << "8. Listar proyectos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1 || opcion == 2) {
            int n;
            cout << "Ingrese el numero de tareas a agregar: ";
            cin >> n;
            cin.ignore();
            
            for (int i = 0; i < n; i++) {
                string titulo, fecha, usuario;
                cout << "Ingrese titulo: "; getline(cin, titulo);
                cout << "Ingrese fecha limite: "; getline(cin, fecha);
                cout << "Ingrese usuario asignado: "; getline(cin, usuario);
                
                if (opcion == 1) {
                    gestor.agregarTarea(new TareaGeneral(titulo, fecha, usuario));
                } else {
                    int urgencia;
                    cout << "Ingrese nivel de urgencia (1-10): "; cin >> urgencia;
                    cin.ignore();
                    gestor.agregarTarea(new TareaUrgente(titulo, fecha, usuario, urgencia));
                }
            }
        }
        else if (opcion == 3) {
            gestor.listarTareas();
        }
        else if (opcion == 4) {
            int num;
            string nuevoEstado;
            gestor.listarTareas();
            cout << "Seleccione el numero de tarea para actualizar: "; cin >> num;
            cin.ignore();
            cout << "Ingrese nuevo estado: "; getline(cin, nuevoEstado);
            gestor.actualizarEstadoTarea(num - 1, nuevoEstado);
        }
        else if (opcion == 5) {
            if (numProyectos < 10) {
                string nombre;
                cout << "Ingrese el nombre del proyecto: ";
                getline(cin, nombre);
                proyectos[numProyectos++] = Proyecto(nombre);
            } else {
                cout << "No se pueden crear más proyectos.\n";
            }
        }
        else if (opcion == 6) {
            if (numProyectos == 0) {
                cout << "No hay proyectos creados.\n";
                continue;
            }
            int index;
            string comentario;
            cout << "Seleccione el numero de proyecto: ";
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= numProyectos) {
                cout << "Ingrese comentario: ";
                getline(cin, comentario);
                proyectos[index - 1].agregarComentario(comentario);
            } else {
                cout << "Proyecto invalido.\n";
            }
        }
        else if (opcion == 7) {
            if (numProyectos == 0) {
                cout << "No hay proyectos creados.\n";
                continue;
            }
            int index;
            string archivo;
            cout << "Seleccione el numero de proyecto: ";
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= numProyectos) {
                cout << "Ingrese el nombre del archivo a compartir: ";
                getline(cin, archivo);
                proyectos[index - 1].compartirArchivo(archivo);
            } else {
                cout << "Proyecto invalido.\n";
            }
        }
        else if (opcion == 8) {
            if (numProyectos == 0) {
                cout << "No hay proyectos creados.\n";
                continue;
            }
            for (int i = 0; i < numProyectos; i++) {
                cout << i + 1 << ". ";
                proyectos[i].mostrar();
            }
        }
    } while (opcion != 0);
    return 0;
}
