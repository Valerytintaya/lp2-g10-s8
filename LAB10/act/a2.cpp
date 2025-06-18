#include <iostream>
#include <cmath>
using namespace std;

class Ruta{  //Creamos la clase Ruta con sus atributos correspondientes
private:
    string origen;
    string destino;
public:
    Ruta(string origen, string destino) : origen(origen), destino(destino) {}
    string getOrigen(){
        return this->origen;
    }
    string getDestino(){
        return this->destino;
    }

    template <typename A, typename B>  //Creamos la plantilla para el método asignarVehiculo(), recepcionará 2 tipos de datos
    void asignarVehiculo (A vehiculo,B velocidad){
        cout << "Se asigno el vehiculo " << vehiculo 
             << " a la ruta " << origen << "-" << destino 
             << " con velocidad: " << velocidad << endl;
    }

    template <typename C>  //Creamos otra plantilla para el método calcularDistancia(), recepcionará sólo 1 tipo de dato
    C calcularDistancia(C px1, C py1, C px2, C py2){
        return sqrt(pow(px2 - px1, 2) + pow(py2 - py1, 2));
    }
};

class Entrega{  //Creamos la clase Entrega con sus atributos correspondientes
private:
    string direccion;
public:
    Entrega(string direccion) : direccion(direccion) {}
    template <typename D>  //Creamos la plantilla para el método tiempoEntrega(), recepcionará sólo 1 tipo de dato
    D tiempoEntrega(D dis, D vel){
        return dis / vel;
    }
};
class Reporte{  //Creamos la clase Reporte con sus atributos correspondientes
private:
    string persona;
    int num_reporte;
public:
    Reporte(string persona, int num_reporte) 
    : persona(persona), num_reporte(num_reporte) {}
    template <typename E, typename F>  //Creamos la plantilla para el método generarReporte(), recepionará 2 tipos de datos

    void generarReporte(E r, F d, F t){
    cout << "REPORTE" << endl;
    cout << "Nombre de la Ruta: " << r << endl;
    cout << "Distancia: " << d << " metros" << endl;
    cout << "Tiempo estimado: " << t << " horas" << endl;
    }
};

int main(){

    Ruta r1("Arequipa","Chivay");  //Creamos un objeto tipo Ruta y brindamos los argumentos

    cout << "Ruta: " << r1.getOrigen() << "-" << r1.getDestino() << endl;
    cout << "Distancia: " << r1.calcularDistancia(50,100,450,300) << " metros" << endl;

    r1.asignarVehiculo("Bus A",60);
    Entrega e1("other place");  //Creamos un objeto tipo Entrega y brindamos los argumentos

    cout << "Tiempo estimado: " << e1.tiempoEntrega(r1.calcularDistancia(50,100,450,300), 60) << " horas" << endl;

    Reporte rep1("Luis",01);  //Creamos un objeto tipo Reporte y brindamos los argumentos

    rep1.generarReporte(r1.getOrigen() + r1.getDestino(),
    r1.calcularDistancia(50,100,450,300),e1.tiempoEntrega(r1.calcularDistancia(50,100,450,300),60));

    return 0;
}
