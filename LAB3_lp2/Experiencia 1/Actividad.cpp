#include <iostream>
#include <string>

// A) Módulo de la Tarea: Se encarga de la gestión de las tareas.
class Tarea {
private:
    std::string titulo;
    std::string fechaLimite;
    int progreso;

public:
    // B) Crear clases con una sola responsabilidad: La Tarea se encarga solo de gestionar los atributos de la tarea
    Tarea(std::string t, std::string f, int p = 0) {
        titulo = t;
        fechaLimite = f;
        progreso = p;
    }

    void mostrarTarea() {
        std::cout << "Tarea: " << titulo << "\n";
        std::cout << "Fecha Limite: " << fechaLimite << "\n";
        std::cout << "Progreso: " << progreso << "%\n";
    }

    void actualizarProgreso(int p) {
        if (p >= 0 && p <= 100) {
            progreso = p;
        }
    }

    bool estaCompletada() {
        return progreso == 100;
    }

    std::string obtenerTitulo() {
        return titulo;
    }
};

// A) Módulo de Usuario: La clase Usuario se encarga solo de representar la información del usuario.
class Usuario {
private:
    std::string nombre;

public:
    // B) Crear clases con una sola responsabilidad: El Usuario solo contiene su nombre.
    Usuario(std::string n) : nombre(n) {}

    std::string obtenerNombre() {
        return nombre;
    }
};

// A) Módulo de Gestión de Tareas: Se encarga de asignar y mostrar las tareas.
class GestorTareas {
private:
    Tarea* tareaAsignada;

public:
    // B) Crear clases con una sola responsabilidad: El GestorTareas solo asigna y muestra las tareas.
    void asignarTarea(Tarea* t) {
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
    // C) Asegurarse de que cada módulo tenga un único propósito y tareas claramente definidas.
    // Crear un usuario
    Usuario usuario("Juan Perez");

    // Crear una tarea
    Tarea tarea("Desarrollar aplicación de gestión de tareas", "2025-05-01", 0);

    // Crear un gestor de tareas y asignarle la tarea
    GestorTareas gestor;
    gestor.asignarTarea(&tarea);

    // Mostrar la tarea asignada
    std::cout << "Usuario: " << usuario.obtenerNombre() << "\n";
    gestor.mostrarTarea();

    // Actualizar el progreso de la tarea
    std::cout << "\nActualizando el progreso a 50%\n";
    gestor.actualizarProgreso(50);
    gestor.mostrarTarea();

    // Actualizar el progreso de la tarea a 100%
    std::cout << "\nActualizando el progreso a 100%\n";
    gestor.actualizarProgreso(100);
    gestor.mostrarTarea();

    return 0;
}
