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
public class Main_Test_Quadrato {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int lato = 10;
        Quadrato q = new Quadrato(lato);
        System.out.println("Area del quadrato di lato " + lato + ": " + q.area());
        System.out.println("Diagonale del quadrato di lato " + lato + ": " + q.getDiagonale());
    }
    
}
