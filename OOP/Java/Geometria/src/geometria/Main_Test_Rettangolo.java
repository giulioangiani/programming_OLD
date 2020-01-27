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
public class Main_Test_Rettangolo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        int base = 30;
        int altezza = 40;
        Rettangolo r = new Rettangolo(base, altezza);
        System.out.println("Area del rettangolo : " + r.area());
        System.out.println("Diagonale del rettangolo: " + r.getDiagonale());
    }
    
}
