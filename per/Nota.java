class Nota {
    float nota;
    Estudiante es;
    Asignatura asig;

    public Nota(float n, Asignatura a) {
        nota = n;
        asig = a;
    }

    public void mostrar() {
        System.out.println("Asignatura: " + asig.nombre + " Nota: " + nota);
    }
}
