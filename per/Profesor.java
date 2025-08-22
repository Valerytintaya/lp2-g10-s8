import java.util.ArrayList;
class Profesor {
    String nombre, direc, telefono;
    ArrayList<Asignatura> asigs;

    public Profesor(String n, String d, String t) {
        nombre = n;
        direc = d;
        telefono = t;
        asigs = new ArrayList<>();
    }

    public void agregarAsignatura(Asignatura nueva) {
        asigs.add(nueva);
        System.out.println("Agregado exitosamente...");
    }

    public void mostrarAsignaturas() {
        System.out.println("Asignaturas de " + nombre + ":");
        for (Asignatura a : asigs) {
            a.mostrarInfo();
        }
    }

    public void mostrarProfesor() {
        System.out.println(" - " + nombre + " - " + telefono);
    }
}
