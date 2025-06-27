#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Evento {
private:
    string nombre;
    string fecha;
    vector<string> asistentes;

public:
    Evento() {}
    Evento(string nombreEvento, string fechaEvento) : nombre(nombreEvento), fecha(fechaEvento) {}

    string getNombre() const { return nombre; }
    string getFecha() const { return fecha; }

    void agregarAsistente(string asistente) {
        asistentes.push_back(asistente);
    }

    void mostrarAsistentesOrdenados() const {
        vector<string> copia = asistentes;
        sort(copia.begin(), copia.end());
        cout << "Asistentes (ordenados alfabéticamente):\n";
        for (const string& a : copia) {
            cout << "- " << a << endl;
        }
    }

    bool tieneFecha(const string& f) const {
        return fecha == f;
    }

    void mostrarResumen() const {
        cout << "Evento: " << nombre << " | Fecha: " << fecha << " | Asistentes: " << asistentes.size() << endl;
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n--- Menú de Organización de Eventos ---\n";
    cout << "1. Agregar nuevo evento\n";
    cout << "2. Agregar asistente a un evento\n";
    cout << "3. Mostrar asistentes ordenados por evento\n";
    cout << "4. Buscar eventos por fecha\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    map<string, Evento> eventos; // Clave: 
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            string nombre, fecha;
            cout << "Ingrese nombre del evento: ";
            cin>>nombre;

            if (eventos.count(nombre)) {
                cout << "El evento ya existe.\n";
            } else {
                cout << "Ingrese fecha del evento: ";
                cin>>fecha;
                eventos[nombre] = Evento(nombre, fecha);
                cout << "Evento agregado exitosamente.\n";
            }

        } else if (opcion == 2) {
            string nombreEvento, asistente;

            
            if (!eventos.empty()){
            cout << "Ingrese nombre del evento: ";
            cin>>nombreEvento;

            auto it = eventos.find(nombreEvento);
            if (it != eventos.end()) {
                cout << "Ingrese nombre del asistente: ";
                cin>>asistente;
                it->second.agregarAsistente(asistente);
                cout << "Asistente agregado.\n";
            } else {
                cout << "Evento no encontrado.\n";
            }
            }
            else{
                cout<<"map vacio"<<endl;
            }

        } else if (opcion == 3) {
            string nombreEvento;
            if (!eventos.empty()){
            cout << "Ingrese nombre del evento: ";
            cin>>nombreEvento;
            auto it = eventos.find(nombreEvento);
            if (it != eventos.end()) {
                it->second.mostrarAsistentesOrdenados();
            } else {
                cout << "Evento no encontrado.\n";
            }
            }
            else{
                cout<<"map vacio"<<endl;
            }

        } else if (opcion == 4) {
            string fechaBusqueda;
            if (!eventos.empty()){
            cout << "Ingrese la fecha a buscar: ";
            cin>>fechaBusqueda;

            bool encontrado = false;
            for (const auto& par : eventos) {
                if (par.second.tieneFecha(fechaBusqueda)) {
                    par.second.mostrarResumen();
                    encontrado = true;
                }
            }
            if (!encontrado) {
                cout << "No se encontraron eventos en esa fecha.\n";
            }
            }
            else{
                cout<<"map vacio"<<endl;
            }

        } else if (opcion == 5) {
            cout << "Saliendo del sistema...\n";
        } else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 5);

    return 0;
}
