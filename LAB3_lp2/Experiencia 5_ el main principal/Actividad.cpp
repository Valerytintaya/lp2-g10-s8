#include <iostream>
#include <string>

class ITarea {
public:
    virtual void mostrarTarea() = 0;
    virtual void actualizarProgreso(int p) = 0;
    virtual bool estaCompletada() = 0;
    virtual std::string obtenerTitulo() = 0;
};

class IUsuario {
public:
    virtual std::string obtenerNombre() = 0;
};

class IGestorTareas {
public:
    virtual void asignarTarea(ITarea* t) = 0;
    virtual void mostrarTarea() = 0;
    virtual void actualizarProgreso(int progreso) = 0;
};

// A) Asegurarse de que las dependencias de alto nivel no dependan de las dependencias de bajo nivel.
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

// B) Utilizar interfaces para que los módulos de alto nivel no dependan directamente de los módulos de bajo nivel.
class Usuario : public IUsuario {
private:
    std::string nombre;

public:
    Usuario(std::string n) : nombre(n) {}

    std::string obtenerNombre() override {
        return nombre;
    }
};

// C) Asegurarse de que los cambios en una dependencia de bajo nivel no afecten a los módulos de alto nivel.
class GestorTareas : public IGestorTareas {
private:
    ITarea* tareaAsignada;

public:
    void asignarTarea(ITarea* t) override {
        tareaAsignada = t;
    }

    void mostrarTarea() override {
        if (tareaAsignada != nullptr) {
            tareaAsignada->mostrarTarea();
        } else {
            std::cout << "No hay tareas asignadas.\n";
        }
    }

    void actualizarProgreso(int progreso) override {
        if (tareaAsignada != nullptr) {
            tareaAsignada->actualizarProgreso(progreso);
        }
    }
};

int main() {
    Usuario usuario("Juan Perez");

    Tarea tarea("Desarrollar aplicación de gestión de tareas", "2025-05-01", 0);

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
