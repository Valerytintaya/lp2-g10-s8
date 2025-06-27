#include <iostream>
#include <vector>
#include <algorithm> // para sort, max_element, min_element
using namespace std;

void mostrarVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numeros;
    int n, valor;

    cout << "Ingrese la cantidad de numeros: ";
    cin >> n;

    cout << "Ingrese los numeros enteros:\n";
    for (int i = 0; i < n; ++i) {
        cin >> valor;
        numeros.push_back(valor);
    }

    int suma = 0;
    for (int num : numeros) {
        suma += num;
    }

    int maximo = *max_element(numeros.begin(), numeros.end());
    int minimo = *min_element(numeros.begin(), numeros.end());

    sort(numeros.begin(), numeros.end());

    numeros.erase(remove_if(numeros.begin(), numeros.end(),
                [](int x) { return x % 2 == 0; }), numeros.end());

    cout << "\n--- Resultados ---\n";
    cout << "Suma total: " << suma << endl;
    cout << "Número máximo: " << maximo << endl;
    cout << "Número mínimo: " << minimo << endl;
    cout << "Vector final (sin números pares, ordenado): ";
    mostrarVector(numeros);

    return 0;
}
