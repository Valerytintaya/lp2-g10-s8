#include <iostream>
using namespace std;

template <typename T>
class Recipiente {
private:
    T* arr;  
    int n;   

public:
    Recipiente(T arr[], int n) {
        this->n = n;  
        this->arr = new T[n];  

        for (int i = 0; i < n; ++i) {
            this->arr[i] = arr[i];
        }
    }
    ~Recipiente() {
        delete[] arr;
    }

    void ordenar() {
        // Recorrer el arreglo
        for (int i = 0; i < n-1; ++i) {
            // Comparar y cambiar de posición si es necesario
            for (int j = 0; j < n-i-1; ++j) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    // Método para imprimir el arreglo
    void imprimir() const {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;  // Nueva línea al final
    }
};

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};

    Recipiente<int> recipiente(arr, 6);

    cout << "Arreglo original: ";
    recipiente.imprimir();

    recipiente.ordenar();

    cout << "Arreglo ordenado: ";
    recipiente.imprimir();

    return 0;  
}

