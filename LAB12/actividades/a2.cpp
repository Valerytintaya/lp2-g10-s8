#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <cctype> // para toupper
using namespace std;

void mostrarLista(const list<string>& palabras) {
    for (const string& palabra : palabras) {
        cout << palabra << " ";
    }
    cout << endl;
}

string aMayusculas(string str) {
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return toupper(c);
    });
    return str;
}

int main() {
    list<string> palabras;
    string entrada, buscar;
    int cantidad;

    cout << "¿Cuántas palabras desea ingresar?: ";
    cin >> cantidad;

    cout << "Ingrese las palabras:\n";
    for (int i = 0; i < cantidad; ++i) {
        cin >> entrada;
        palabras.push_back(entrada);
    }

    palabras.sort();
    cout << "Ingrese una palabra para contar cuántas veces aparece: ";
    cin >> buscar;
    int ocurrencias = count(palabras.begin(), palabras.end(), buscar);

    transform(palabras.begin(), palabras.end(), palabras.begin(), aMayusculas);

    cout << "\n--- Lista ordenada y en mayúsculas ---\n";
    mostrarLista(palabras);

    cout << "\nLa palabra \"" << buscar << "\" aparece " << ocurrencias << " veces (antes de convertir a mayúsculas)." << endl;
    return 0;
}
