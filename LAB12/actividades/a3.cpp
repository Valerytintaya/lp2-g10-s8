#include <iostream>
#include <deque>
#include <string>
#include <cctype> // para tolower
using namespace std;

bool esVocal(char c) {
    char min = tolower(c);
    return (min == 'a' || min == 'e' || min == 'i' || min == 'o' || min == 'u');
}

int main() {
    deque<char> caracteres;
    string cadena;

    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cadena); // Permite espacios

    for (char c : cadena) {
        caracteres.push_back(c);
    }

    cout << "\nCaracteres uno por uno:\n";
    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (deque<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
        if (esVocal(*it)) {
            *it = '*';
        }
    }

    cout << "\nCaracteres en orden inverso:\n";
    for (deque<char>::reverse_iterator rit = caracteres.rbegin(); rit != caracteres.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    cout << "\nCadena modificada:\n";
    for (char c : caracteres) {
        cout << c;
    }
    cout << endl;

    return 0;
}
