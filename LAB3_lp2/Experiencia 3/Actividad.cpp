#include <iostream>
#include <string>

class ITarea {
public:
    virtual void mostrarTarea() = 0;
    virtual void actualizarProgreso(int p) = 0;
    virtual bool estaCompletada() = 0;
    virtual std::string obtenerTitulo() = 0;
};

class Tarea : public ITarea {
private:
    std::string titulo;
    std::string fechaLimite;
    int progreso;

public:
    Tarea(std::string t, std::string f, int p = 0) : titulo(t), fechaLimite(f), progreso(p) {}

    void mostrarTarea() override {
        std::cout << "Tarea: " << titulo << "\n";
        std::cout << "Fecha Limite: " << fechaLimite << "\n";
        std::cout << "Progreso: " << progreso << "%\n";
    }

    void actualizarProgreso(int p) override {
        if (p >= 0 && p <= 100) {
            progreso = p;
        }
    }

    bool estaCompletada() override {
        return progreso == 100;
    }

    std::string obtenerTitulo() override {
        return titulo;
    }
};

// A) Asegurarse de que las subclases sean intercambiables con las clases padre sin afectar el comportamiento de la aplicación.
class TareaPrioritaria : public Tarea {
private:
    int prioridad;

public:
    TareaPrioritaria(std::string t, std::string f, int p = 0, int pr = 1) : Tarea(t, f, p), prioridad(pr) {}

    void mostrarTarea() override {
        std::cout << "Tarea Prioritaria: " << obtenerTitulo() << "\n";
        std::cout << "Fecha Limite: " << obtenerTitulo() << "\n";
        std::cout << "Progreso: " << obtenerTitulo() << "%\n";
        std::cout << "Prioridad: " << prioridad << "\n";  // Añadido solo para mostrar la prioridad, no altera la funcionalidad de la clase base
    }
};

class IUsuario {
public:
    virtual std::string obtenerNombre() = 0;
};

class Usuario : public IUsuario {
private:
    std::string nombre;

public:
    Usuario(std::string n) : nombre(n) {}

    std::string obtenerNombre() override {
        return nombre;
    }
};

class GestorTareas {
private:
    ITarea* tareaAsignada;

public:
    void asignarTarea(ITarea* t) {
        tareaAsignada = t;
    }

    void mostrarTarea() {
        if (tareaAsignada != nullptr) {
            tareaAsignada->mostrarTarea();
        } else {
            std::cout << "No hay tareas asignadas.\n";
        }
    }

    void actualizarProgreso(int progreso) {
        if (tareaAsignada != nullptr) {
            tareaAsignada->actualizarProgreso(progreso);
        }
    }
};

int main() {
    Usuario usuario("Juan Perez");

    // Usamos una TareaPrioritaria en lugar de una Tarea normal
    TareaPrioritaria tarea("Desarrollar aplicación de gestión de tareas", "2025-05-01", 0, 1);

    GestorTareas gestor;
    gestor.asignarTarea(&tarea);

    std::cout << "Usuario: " << usuario.obtenerNombre() << "\n";
    gestor.mostrarTarea();

    std::cout << "\nActualizando el progreso a 50%\n";
    gestor.actualizarProgreso(50);
    gestor.mostrarTarea();

    std::cout << "\nActualizando el progreso a 100%\n";
    gestor.actualizarProgreso(100);
    gestor.mostrarTarea();

    return 0;
}
