/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esempi;

import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

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
        
        ArrayList<Integer> pippo = new ArrayList<>();
        pippo.add(5);
        pippo.add(1);
        pippo.add(10);
        System.out.println("Size: " + pippo.size());
        System.out.println("Contenuto " + pippo);
        
        ArrayList<Pet> mypets = new ArrayList<>();
        mypets.add(new Pet("Molly"));
        mypets.add(new Pet("Baffo"));
        System.out.println("Size: " + mypets.size());
        System.out.println("Contenuto " + mypets);
        
        

    }
    
}
