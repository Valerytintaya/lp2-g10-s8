import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<Estudiante> estudiantes = new ArrayList<>();
    static ArrayList<Profesor> profesores = new ArrayList<>();
    static ArrayList<Asignatura> asignaturas = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int opcion;
        int num;

        do {
            System.out.println("\n--- MENU UNIVERSIDAD ---");
            System.out.println("1. Registrar Estudiante");
            System.out.println("2. Registrar Profesor");
            System.out.println("3. Registrar Asignatura");
            System.out.println("4. Matricular Estudiante");
            System.out.println("5. Registrar Nota");
            System.out.println("6. Registrar Asistencia");
            System.out.println("7. Mostrar Estudiantes");
            System.out.println("0. Salir");
            System.out.print("Opcion: ");
            opcion = sc.nextInt();
            sc.nextLine(); // Limpiar el buffer

            switch (opcion) {
                case 1:
                    System.out.print("Numero de estudiantes a agregar: ");
                    num = sc.nextInt();
                    sc.nextLine();
                    for (int i = 0; i < num; i++) {
                        System.out.print("Nombre: ");
                        String n = sc.nextLine();
                        System.out.print("Direccion: ");
                        String d = sc.nextLine();
                        System.out.print("Matricula: ");
                        String m = sc.nextLine();
                        estudiantes.add(new Estudiante(n, d, m));
                    }
                    break;
                case 2:
                    System.out.print("Numero de profesores a agregar: ");
                    num = sc.nextInt();
                    sc.nextLine();
                    for (int i = 0; i < num; i++) {
                        System.out.print("Nombre: ");
                        String n = sc.nextLine();
                        System.out.print("Direccion: ");
                        String d = sc.nextLine();
                        System.out.print("Telefono: ");
                        String t = sc.nextLine();
                        profesores.add(new Profesor(n, d, t));
                    }
                    break;
                case 3:
                    if (profesores.isEmpty()) {
                        System.out.println("Primero registre profesores");
                        break;
                    }
                    System.out.print("Numero de asignaturas a agregar: ");
                    num = sc.nextInt();
                    sc.nextLine();
                    for (int i = 0; i < num; i++) {
                        System.out.print("Codigo: ");
                        String c = sc.nextLine();
                        System.out.print("Nombre: ");
                        String n = sc.nextLine();
                        System.out.print("Descripcion: ");
                        String d = sc.nextLine();
                        System.out.println("===PROFESORES===");
                        for (int j = 0; j < profesores.size(); j++) {
                            System.out.print((j + 1) + " | ");
                            profesores.get(j).mostrarProfesor();
                        }
                        System.out.print("Profesor (indice): ");
                        int ind = sc.nextInt();
                        sc.nextLine();
                        Profesor p = profesores.get(ind - 1);
                        Asignatura asig = new Asignatura(c, n, d, p);
                        asignaturas.add(asig);
                        p.agregarAsignatura(asig);
                    }
                    break;
                case 4:
                    if (asignaturas.isEmpty() || estudiantes.isEmpty()) {
                        System.out.println("Primero registre estudiantes / asignaturas");
                        break;
                    }
                    System.out.println("\n===ESTUDIANTES===");
                    for (int i = 0; i < estudiantes.size(); i++) {
                        System.out.println(i + 1 + " | " + estudiantes.get(i).nombre);
                    }
                    System.out.print("Estudiante (indice): ");
                    int est = sc.nextInt();
                    sc.nextLine();

                    System.out.println("\n===ASIGNATURAS===");
                    for (int i = 0; i < asignaturas.size(); i++) {
                        System.out.print(i + 1 + " | ");
                        asignaturas.get(i).mostrarInfo();
                    }
                    System.out.print("Asignatura (indice): ");
                    int asig = sc.nextInt();
                    sc.nextLine();
                    estudiantes.get(est - 1).agregarAsignatura(asignaturas.get(asig - 1));
                    break;
                case 5:
                    if (estudiantes.isEmpty()) {
                        System.out.println("Primero matricule algún estudiante...");
                        break;
                    }
                    System.out.println("\n===ESTUDIANTES===");
                    for (int i = 0; i < estudiantes.size(); i++) {
                        System.out.println(i + 1 + " | " + estudiantes.get(i).nombre);
                    }
                    System.out.print("Estudiante (indice): ");
                    est = sc.nextInt();
                    sc.nextLine();

                    System.out.println("\n===ASIGNATURAS===");
                    estudiantes.get(est - 1).mostrarAsigEstu();
                    System.out.print("Asignatura (indice): ");
                    asig = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Nota: ");
                    float nota = sc.nextFloat();
                    Asignatura a = estudiantes.get(est - 1).asigs.get(asig - 1);
                    estudiantes.get(est - 1).agregarNota(new Nota(nota, a));
                    break;
                case 6:
                    if (estudiantes.isEmpty()) {
                        System.out.println("Primero matricule algún estudiante...");
                        break;
                    }
                    System.out.println("\n===ESTUDIANTES===");
                    for (int i = 0; i < estudiantes.size(); i++) {
                        System.out.println(i + 1 + " | " + estudiantes.get(i).nombre);
                    }
                    System.out.print("Estudiante (indice): ");
                    est = sc.nextInt();
                    sc.nextLine();

                    System.out.println("\n===ASIGNATURAS===");
                    estudiantes.get(est - 1).mostrarAsigEstu();
                    System.out.print("Asignatura (indice): ");
                    asig = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Fecha: ");
                    String fecha = sc.nextLine();
                    System.out.print("Presente (s/n): ");
                    char pres = sc.next().charAt(0);
                    a = estudiantes.get(est - 1).asigs.get(asig - 1);
                    estudiantes.get(est - 1).agregarAsistencia(new Asistencia(fecha, pres == 's', a));
                    break;
                case 7:
                    for (Estudiante e : estudiantes) {
                        e.mostrarResumen();
                        System.out.println();
                    }
                    break;
            }
        } while (opcion != 0);

        sc.close();
    }
}
