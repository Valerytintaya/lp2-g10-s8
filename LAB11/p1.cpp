#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept> 
using namespace std;

int main() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de texto (ej. datos.txt): ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);

    try {
        if (archivo.fail()) {
            throw runtime_error("Error: No se pudo abrir el archivo '" + nombreArchivo + "'. Verifique que exista.");
        }

        cout << "\n--- Contenido del archivo ---\n";
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
