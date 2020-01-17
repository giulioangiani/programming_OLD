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
public class Main_Test_CerchioAnalitico {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        CerchioAnalitico c = new CerchioAnalitico(3,5,2);   // x=3, y=5, r=2
        System.out.println("Area del cerchio : " + c.area());
        System.out.println("Circonferenza del cerchio : " + c.circonferenza());
        System.out.println("Distanza cerchio-origine : " + c.distanzaDaOrigine());
    }
    
}
