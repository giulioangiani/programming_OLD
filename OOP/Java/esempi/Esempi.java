/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esempi;

import java.util.ArrayList;

/**
 *
 * @author giulio
 */
public class Esempi {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        

        System.out.println("*****************************************************************");
        System.out.println("*****************  ESEMPIO DI USO DI ARRAYLIST ******************");
        
        
        System.out.println("Stampo tutti gli elementi delll'arraylist");
        ArrayList<Integer> numeri = new ArrayList<>();
        numeri.add(5);
        numeri.add(10);
        numeri.add(8);
        System.out.println("numeri = " + numeri);
        for ( int x : numeri) {
            System.out.println("numero " + x);
        }
        
        
        System.out.println("Stampo tutti gli elementi dell'arraylist con indice ");
        for ( int i = 0; i<numeri.size(); i++) {
            System.out.println("pos. " + i + " : numero " + numeri.get(i));
        }
        

        System.out.println("**********************************************************************");
        System.out.println("*****************  ESEMPIO DI USO DI METODI STATICI ******************");
        // posso chiamare il metodo statico ma non quelli 
        System.out.println("Quanti sono (static) ? " + Pet.quanti());

        ArrayList<Pet> mypets = new ArrayList<>();

        System.out.println("Size inizio: " + mypets.size());

        Pet molly = new Pet("Molly", "AX0912");
        Pet baffo = new Pet("Baffo", "BY8377");
   
        mypets.add(baffo);
        mypets.add(molly);
        
        System.out.println("Baffo = " + baffo);
        
        // numero di oggetti inseriti in ArrayList mypets
        System.out.println("Size fine  : " + mypets.size());
        // La stampa di una ArrayList ha il formato
        // [ <package.classe@indirizzomemoria1>, <package.classe@indirizzomemoria2>, ...]
        // ma se è ridefinito toString() per la classe degli oggetti di ArrayList
        // usa quella per stamparne il contenuto
        System.out.println("Contenuto " + mypets);
        
        // creo un altro oggetto senza metterlo in mypets
        Pet spank = new Pet("Spank", "SP0987");
           
        // numero di oggetti Pet creati usando il metodo statico "quanti()" 
        // questo metodo, a sua volta, usa l'attributo statico di classe
        System.out.println("Quanti sono (static) ? " + Pet.quanti());
            

    }
    
}
