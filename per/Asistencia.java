class Asistencia {
    String fecha;
    boolean presente;
    Estudiante estu;
    Asignatura asig;

    public Asistencia(String f, boolean p, Asignatura a) {
        fecha = f;
        presente = p;
        asig = a;
    }

    public void mostrar() {
        System.out.println("Fecha: " + fecha + " - " + asig.nombre + " - " + (presente ? "Presente" : "Ausente"));
    }
}
