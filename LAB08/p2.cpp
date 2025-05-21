#include <iostream>
using namespace std;

// Interfaz Reproductor
class Reproductor {
public:
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;

    virtual ~Reproductor() {} // Destructor virtual
};

// Clase que implementa la interfaz
class ReproductorMP3 : public Reproductor {
public:
    void reproducir() override {
        cout << "Reproduciendo archivo MP3..." << endl;
    }

    void pausar() override {
        cout << "Pausando reproducción." << endl;
    }

    void detener() override {
        cout << "Deteniendo reproducción." << endl;
    }
};

// Función principal
int main() {
    // Crear una instancia de ReproductorMP3
    Reproductor* mp3 = new ReproductorMP3();

    // Probar los métodos
    mp3->reproducir();
    mp3->pausar();
    mp3->detener();

    // Liberar memoria
    delete mp3;

    return 0;
}
