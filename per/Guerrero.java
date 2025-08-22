
public class Guerrero extends Personaje {
    protected int cantFuerza;
    public static final String tipo = "Guerrero";
    
    public Guerrero(String nombre, int nivel, int ataque, int cantFuerza) {
        super(nombre, nivel, ataque);
        this.cantFuerza=cantFuerza;
    }

    @Override
    public void atacar(Personaje n){
        System.out.println(nombre +"a atacado a: " + n.nombre);
        n.recibir(ataque+cantFuerza);
    }

    @Override
    public void mostrar(){
        mostrarInfo();
        System.out.println("Cantidad de fuerza: "+cantFuerza);
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
