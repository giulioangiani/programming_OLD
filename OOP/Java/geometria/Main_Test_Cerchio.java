/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package geometria;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author giulio
 */
public class Main_Test_Cerchio {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Cerchio c;
        
        Scanner s = new Scanner(System.in);
        while (true) {
            try {
                System.out.print("Inserisci la dimensione del raggio (deve essere un numero positivo) : ");
                c = new Cerchio(Float.parseFloat(s.nextLine()));
                break;
            } catch (Exception ex) {
                System.out.println("input non valido");      
            }
            
        }
        System.out.println("Area del cerchio : " + c.area());
        System.out.println("Circonferenza del cerchio : " + c.circonferenza());
    }
    
}
