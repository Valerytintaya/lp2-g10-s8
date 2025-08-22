
import java.util.Scanner;
import java.util.Vector;

public class min {
    public static void main(String[] args) {
        Scanner entrada= new Scanner(System.in);
        Vector <Personaje> personajes= new Vector<>();
        while (true) { 
           System.out.println("""
                              === MENU PRINCIPAL ===
                              1. crear personaje
                              2. atacar
                              3. curar
                              4. mostrar información
                              5. salir""");
            System.out.print("opcion: ");
            int op=entrada.nextInt();
            entrada.nextLine();

            if(op==1){
            while (true) { 
                System.out.println("""
                              1. Guerrero
                              2. Mago
                              3. salir""");
                System.out.print("opcion: ");
                int op1=entrada.nextInt();
                entrada.nextLine();

                if (op1==1) {
                    System.out.print("Ingrese el nombre del guerrero: ");
                    String nombre = entrada.nextLine();

                    System.out.print("Ingrese el nivel del guerrero: ");
                    int nivel = entrada.nextInt();

                    int ataque;
                    do {
                        System.out.print("Ingrese el ataque del guerrero (cantidad 1-20): ");
                        ataque = entrada.nextInt();
                    } while (ataque < 1 || ataque > 20);

                    int cantFuerza;
                    do {
                        System.out.print("Ingrese la cantidad de fuerza del guerrero (1-15): ");
                        cantFuerza = entrada.nextInt();
                    } while (cantFuerza < 1 || cantFuerza > 15);

                    Guerrero g=new Guerrero(nombre, nivel, ataque, cantFuerza);
                    personajes.add(g); // push:back=add
                    System.out.println("GUERRERO CREADO ");
                }

                if (op1==2) {
                    System.out.print("Ingrese el nombre del mago: ");
                    String nombre = entrada.nextLine();

                    System.out.print("Ingrese el nivel del mago: ");
                    int nivel = entrada.nextInt();

                    int ataque;
                    do {
                        System.out.print("Ingrese el ataque del mago (cantidad 1-20): ");
                        ataque = entrada.nextInt();
                    } while (ataque < 1 || ataque > 20);


                    int cantFuerza;
                    do {
                        System.out.print("Ingrese la cantidad de mana del mago (1-15): ");
                        cantFuerza = entrada.nextInt();
                    } while (cantFuerza < 1 || cantFuerza > 15);

                    Mago m=new Mago(nombre, nivel, ataque, cantFuerza);
                    personajes.add(m); // push:back=add
                    System.out.println("mago CREADO ");
                }

                if (op1==3){
                    System.out.println("saliendo........");
                    break;
                }
            }

            } else if (op == 2) { // Atacar
                if (personajes.size() < 2) {
                    System.out.println("Debe haber al menos 2 personajes para atacar.");
                } else {
                    System.out.println("Seleccione al atacante:");
                    for (int i = 0; i < personajes.size(); i++) {
                        System.out.println(i + ". " + personajes.get(i).getNombre()+"| "+personajes.get(i).getTipo());
                    }
                    System.out.print("opcion: ");
                    int atacante = entrada.nextInt();
                    entrada.nextLine();

                    System.out.println("Seleccione al objetivo:");
                    for (int i = 0; i < personajes.size(); i++) {
                        if (i != atacante) {
                            System.out.println(i + ". " + personajes.get(i).getNombre()+"| "+personajes.get(i).getTipo());
                        }
                    }
                    System.out.print("opcion: ");
                    int objetivo = entrada.nextInt();
                    entrada.nextLine();

                    personajes.get(atacante).atacar(personajes.get(objetivo));
                }
            }else if (op == 3) { // Curar
                if (personajes.isEmpty()) {
                    System.out.println("No hay personajes para curar.");
                } else {
                    System.out.println("Seleccione al personaje a curar:");
                    for (int i = 0; i < personajes.size(); i++) {
                        if (personajes.get(i).getVida()!=100) {
                            System.out.println(i + ". " + personajes.get(i).getNombre()+"| "+personajes.get(i).getTipo());
                        }
                    }
                    System.out.print("opcion: ");
                    int idx = entrada.nextInt();
                    entrada.nextLine();

                    personajes.get(idx).curar(10);
                }
            }else if (op == 4) { // Mostrar info
                if (personajes.isEmpty()) {
                    System.out.println("No hay personajes registrados.");
                } else {
                    for (int i = 0; i < personajes.size(); i++) {
                        System.out.println("[" + i + "]");
                        personajes.get(i).mostrar();
                    }
                }
            }
            else if (op == 5) {
                System.out.println("Saliendo...");
                break;
            }

        }


    }
}
