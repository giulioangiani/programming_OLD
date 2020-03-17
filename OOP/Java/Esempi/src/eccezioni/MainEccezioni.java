/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package eccezioni;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author giulio
 */
public class MainEccezioni {

    public static int leggiNumero() throws NumeroTroppoAltoException {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        if (x > 100) throw new NumeroTroppoAltoException();
        return x;
    }
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            // TODO code application logic here
            
            Scanner sc = new Scanner(System.in);
            System.out.print("Inserisci numeratore : ");
            String s1 = sc.nextLine();
            System.out.print("Inserisci denominatore : ");
            String s2 = sc.nextLine();
            boolean error = false;
            try {
            int num = Integer.parseInt(s1);
            System.out.println("N = " + num);
            int den = Integer.parseInt(s2);
            System.out.println("D = " + den);
            
            File file = new File ("/tmp/test4.txt");
            FileInputStream fis = new FileInputStream(file);

            float frazione = num/den;
            System.out.println("frazione = " + frazione);
            }
            catch (NumberFormatException ex) {
            //ex.printStackTrace();
            System.out.println("Errore in parseInt : " + ex.getMessage());
            error = true;
            }
            catch (ArithmeticException ex) {
            //ex.printStackTrace();
            System.out.println("Errore in calcolo frazione : " + ex.getMessage());
            error = true;
            }
            catch (FileNotFoundException ex) {
            //ex.printStackTrace();
            System.out.println("File not found : " + ex.getMessage());
            error = true;
            }
            catch (Exception ex) {
            //ex.printStackTrace();
            System.out.println("Errore generico : " + ex.getMessage());
            error = true;
            }
            finally {
            System.out.println("Fine del blocco try");
            if (error) {
            System.out.println("ERRORI RILEVATI");
            }
            else {
            System.out.println("NESSUN ERRORE RILEVATO");
            }
            }
            
            System.out.print("Inserisci un numero : ");
            int a = leggiNumero();
            System.out.println("A = " + a);
        } catch (NumeroTroppoAltoException ex) {
            System.out.println("errore: " + ex.getMessage());
        }
        
        
    }
 
      
    
}
