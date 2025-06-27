#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Contacto {
    string telefono;
    string email;
};

int main() {
    map<string, Contacto> agenda;
    int opcion;
    string nombre;

    do {
        cout << "\n--- AGENDA DE CONTACTOS ---\n";
        cout << "1. Agregar contacto\n";
        cout << "2. Buscar contacto\n";
        cout << "3. Actualizar contacto\n";
        cout << "4. Mostrar lista ordenada\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Contacto c;
                cout << "Nombre: ";
                cin>>nombre;
                cout << "Teléfono: ";
                cin>>c.telefono;
                cout << "Correo: ";
                cin>>c.email;
                agenda[nombre] = c;
                cout << "Contacto agregado correctamente.\n";
                break;
            }
            case 2: {
                cout << "Ingrese el nombre a buscar: ";
                cin>>nombre;
                auto it = agenda.find(nombre);
                if (it != agenda.end()) {
                    cout << "Teléfono: " << it->second.telefono << "\n";
                    cout << "Correo: " << it->second.email << "\n";
                } else {
                    cout << "Contacto no encontrado.\n";
                }
                break;
            }
            case 3: {
                cout << "Ingrese el nombre del contacto a actualizar: ";
                cin>>nombre;
                auto it = agenda.find(nombre);
                if (it != agenda.end()) {
                    cout << "Nuevo teléfono: ";
                    cin>>it->second.telefono;
                    cout << "Nuevo correo: ";
                    cin>>it->second.email;
                    cout << "Información actualizada.\n";
                } else {
                    cout << "Contacto no encontrado.\n";
                }
                break;
            }
            case 4: {
                cout << "--- LISTA DE CONTACTOS ORDENADA ---\n";
                for (auto it = agenda.begin(); it != agenda.end(); ++it) {
                    cout << "Nombre: " << it->first << "\n";
                    cout << "  Teléfono: " << it->second.telefono << "\n";
                    cout << "  Correo: " << it->second.email << "\n";
                }

                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}
