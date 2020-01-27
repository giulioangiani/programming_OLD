/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package geometria;

/**
 *
 * @author giulio
 */
public class Main_Test_Triangolo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // primo triangolo istanziato con base e altezza - primo Costuttore
        Triangolo t1 = new Triangolo(10, 5);
        System.out.println("Area di t1 = " + t1.area());
        
        // secondo triangolo istanziato con i tre lati - secondo Costuttore
        Triangolo t2 = new Triangolo(10, 20, 25);
        System.out.println("Area di t2 = " + t2.area());
        
        // terzo triangolo istanziato con tre lati non coerenti - restituisce un errore
        Triangolo t3 = new Triangolo(10, 20, 40); // 40 > 10+20 !!!!
        
    }
    
}
