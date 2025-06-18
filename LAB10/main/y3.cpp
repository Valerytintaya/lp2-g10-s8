#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Template de clase
template <typename T>
class SistemaRutas {
private:
    struct Ruta {
        T id;
        string destino;
        double distancia;
    };

    vector<Ruta> rutas;

public:
    void agregarRuta(T id, string destino, double distancia) {
        rutas.push_back({id, destino, distancia});
    }

    void mostrarRutas() {
        cout << "Reporte de Rutas:\n";
        for (const auto& ruta : rutas) {
            cout << "ID: " << ruta.id
                 << ", Destino: " << ruta.destino
                 << ", Distancia: " << ruta.distancia << " km\n";
        }
    }

    double calcularDistanciaTotal() {
        double total = 0;
        for (const auto& ruta : rutas) {
            total += ruta.distancia;
        }
        return total;
    }
};


int main() {
    // Instancia con rutas de tipo string (alfanumérico)
    SistemaRutas<string> sistemaStr;
    sistemaStr.agregarRuta("R001", "Lima", 150.5);
    sistemaStr.agregarRuta("R002", "Cusco", 320.0);
    sistemaStr.mostrarRutas();
    cout << "Distancia total: " << sistemaStr.calcularDistanciaTotal() << " km\n\n";

    // Instancia con rutas de tipo int (numérico)
    SistemaRutas<int> sistemaInt;
    sistemaInt.agregarRuta(101, "Piura", 230.0);
    sistemaInt.agregarRuta(102, "Tacna", 850.75);
    sistemaInt.mostrarRutas();
    cout << "Distancia total: " << sistemaInt.calcularDistanciaTotal() << " km\n";

    return 0;
}
