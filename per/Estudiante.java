import java.util.ArrayList;
import java.util.Scanner;

class Estudiante {
    String nombre, direc, matri;
    ArrayList<Asignatura> asigs;
    ArrayList<Nota> nota;
    ArrayList<Asistencia> asisten;

    public Estudiante(String n, String d, String m) {
        nombre = n;
        direc = d;
        matri = m;
        asigs = new ArrayList<>();
        nota = new ArrayList<>();
        asisten = new ArrayList<>();
    }

    public void agregarAsignatura(Asignatura nueva) {
        asigs.add(nueva);
        System.out.println("Agregado exitosamente...");
    }

    public void agregarNota(Nota n) {
        nota.add(n);
        System.out.println("Agregado exitosamente...");
    }

    public void agregarAsistencia(Asistencia asis) {
        asisten.add(asis);
        System.out.println("Agregado exitosamente...");
    }

    public void mostrarResumen() {
        System.out.println("Estudiante: " + nombre + ", Matricula: " + matri);
        System.out.println("Asignaturas:");
        for (Asignatura a : asigs) a.mostrarInfo();
        System.out.println("Notas:");
        for (Nota n : nota) n.mostrar();
        System.out.println("Asistencias:");
        for (Asistencia a : asisten) a.mostrar();
    }

    public void mostrarAsigEstu() {
        for (int i = 0; i < asigs.size(); i++) {
            System.out.print(i + 1 + " | ");
            asigs.get(i).mostrarInfo();
        }
    }
}





