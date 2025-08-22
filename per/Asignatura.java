class Asignatura {
    String codigo, nombre, descrip;
    Profesor profesor;

    public Asignatura(String c, String n, String m, Profesor p) {
        codigo = c;
        nombre = n;
        descrip = m;
        profesor = p;
    }

    public void mostrarInfo() {
        System.out.println("Codigo: " + codigo + ", Nombre: " + nombre + " - " + descrip + ", Profesor: " + profesor.nombre);
    }
}
