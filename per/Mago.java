public class Mago extends Personaje {
    protected int curacionExtra;
    protected int mana;
    public static final String tipo = "Mago";
    
    public Mago(String nombre, int nivel, int ataque, int mana) {
        super(nombre, nivel, ataque);
        this.curacionExtra=10;
    }

    @Override
    public void atacar(Personaje n){
        System.out.println(this.nombre +"a atacado a: " + n.nombre);
        n.recibir(ataque+mana);
    }

    @Override
    public void mostrar(){
        mostrarInfo();
        System.out.println("Cantidad de mana: "+mana);
        System.out.println("CuracionExtra: "+curacionExtra);
    }
 
    
    @Override
    public void curar(double can){
        double cuaracion=vida*(90)/100;
        double total= cuaracion+can;
        super.curar(total);
    }

    @Override
    public String getNombre(){
        return nombre;
    }
 
    @Override
    public String getTipo(){
        return tipo;
    }
    
    @Override
    public double getVida(){
        return vida;
    }
}
