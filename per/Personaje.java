
abstract  class Personaje {
    // --- Variables ---
    protected  String nombre;          
    protected int nivel;            
    protected double vida;             
    protected int ataque;             
    
    public static int contador = 0; 
    public static final int MAX_VIDA = 100; 

    // --- Constructor ---
    public Personaje(String nombre, int nivel, int ataque) {
        this.nombre = nombre;
        this.nivel = nivel;
        this.ataque = ataque;
        this.vida = MAX_VIDA; // todo personaje empieza con vida máxima
        contador++; // cada vez que se crea un personaje aumenta
    }

    // --- Métodos ---

    public abstract  void atacar(Personaje enemigo);
    public abstract void mostrar();
    public abstract String getNombre();
    public abstract String getTipo();
    public abstract double getVida();

    // solo lo puede usar dentro de la clase)
    protected  void recibir (int danio) {
        this.vida -= danio;
        if (this.vida < 0) this.vida = 0;
        System.out.println(this.nombre + " ha recibido " + danio + " de daño. Vida: " + this.vida);
    }

    // Método protegido
    protected void curar(double  cantidad) {
        this.vida += cantidad;
        if (this.vida > MAX_VIDA) this.vida = MAX_VIDA;
        System.out.println(this.nombre + " se ha curado. Vida: " + this.vida);
    }

    // Método default 
    void mostrarInfo() {
        System.out.println("Nombre: " + this.nombre + " | Nivel: " + this.nivel 
                            + " | Vida: " + this.vida + " | Ataque: " +this.ataque);
    }
    
}




