#include <iostream>
#include <cmath>
using namespace std;

// Función para calcular la distancia entre dos puntos (x1, y1) y (x2, y2)
template <typename A>
A calcularDistancia(A px1, A py1, A px2, A py2) {
    // Usar fórmula de distancia euclidiana: sqrt((x2 - x1)^2 + (y2 - y1)^2)
   return sqrt(pow(px2 - px1, 2) + pow(py2 - py1, 2));
}

// Función para calcular el tiempo de entrega dado la distancia y la velocidad
template <typename B>
B tiempoEntrega(B dis, B vel) {
    // Dividir la distancia entre la velocidad para obtener el tiempo
    return dis / vel;
}

// Función para generar un reporte con la ruta, distancia y tiempo estimado
template <typename C, typename D>
void generarReporte(C r, D d, D t) {
    cout << "REPORTE" << endl;
    cout << "Nombre de la Ruta: " << r << endl;
    cout << "Distancia: " << d << " metros" << endl;
    cout << "Tiempo estimado: " << t << " horas" << endl;
}

// Función para ordenar un arreglo de forma ascendente usando el algoritmo de burbuja
template <typename T>
void ordenarArreglo(T arr[], int tamanio) {
    for (int i = 0; i < tamanio - 1; i++) {
        for (int j = 0; j < tamanio - i - 1; j++) {
            // Comparar elementos adyacentes y intercambiarlos si están en orden incorrecto
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para imprimir un arreglo ordenado
template <typename T>
void imprimirArreglo(T arr[], int tamanio) {
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < tamanio; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    double x1 = 3.0, y1 = 4.0;
    double x2 = 7.0, y2 = 1.0;

    double distancia = calcularDistancia(x1, y1, x2, y2);

    
    double velocidad = 60.0; 
    double tiempo = tiempoEntrega(distancia, velocidad);

    string nombreRuta = "Ruta A - Entrega Principal";
    generarReporte(nombreRuta, distancia, tiempo);

    double distancias[] = {150.5, 120.2, 300.1, 75.9, 98.3};

    ordenarArreglo(distancias, 5);

    // Imprimir arreglo ordenado
    imprimirArreglo(distancias, 5);

    return 0;
}
