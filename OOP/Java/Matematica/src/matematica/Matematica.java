/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matematica;

/**
 *
 * @author giulio
 */
public class Matematica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        
        // test della classe NumeroRazionale
        
        NumeroRazionale nr = new NumeroRazionale(3,4);
        System.out.println("Valore di nr = " + nr.realValue());
        
        NumeroRazionale inv = nr.inverso();
        System.out.println("Valore di inv = " + inv.realValue());
        
    }
    
}
