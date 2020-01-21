/*
    Realizza un programma per gestire una pila di interi di max 10 elementi attraverso una classe
    pila che deve prevedere dei metodi per l'inserimento e per l'estrazione di un elemento.
*/
package pilamain;

import java.util.logging.Level;
import java.util.logging.Logger;

public class PilaMain {
    public static void main(String[] args) {
       Pila p = new Pila(3);
       
       if(p.push(12)) {
           System.out.println("Inserimento avvenuto");
       }
       if(p.push(23)) {
           System.out.println("Inserimento avvenuto");
       }
       if(p.push(35)) {
           System.out.println("Inserimento avvenuto");
       }
       if(p.push(48)) {
           System.out.println("Inserimento avvenuto");
       }
       
       for(int i = 0; i <4; i++) {
           try {
               System.out.println("Valore estratto: " + p.pop());
           } catch (Exception ex) {
               System.out.println(ex.getMessage());
           }
       }
    }
}
