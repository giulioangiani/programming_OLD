/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package compagniatelefonica;

import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author giulio
 */
public class CompagniaTelefonica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Telefonata t = new Telefonata("3331234667", "10:45", 10);
        System.out.println("Ora: " + t.getOra());
        System.out.println("Durata: " + t.getDurata());
        System.out.println("Numero: " + t.getNumeroChiamato());
        
        SIM s = new SIM("3339876543", 50);
        System.out.println("numero: " + s.getNumero());
        s.setNumero("3456789187");
        System.out.println("numero: " + s.getNumero());
        System.out.println("credito: " + s.getCreditoResiduo());
        
        s.addTelefonata(t);
        s.ricaricaCredito(10);
        System.out.println("credito: " + s.getCreditoResiduo());
        System.out.println("Minuti totali " + s.getMinutiTotaliConversazione());
        s.addTelefonata(new Telefonata("3331234667", "13:45", 25));
        s.addTelefonata(new Telefonata("3459876543", "14:00", 10));

        System.out.println("Minuti totali " + s.getMinutiTotaliConversazione());
        
        
        System.out.println("Telefonate verso il numero 3331234667:");
        for (Telefonata t2 : s.getListaTelefonatePerNumero("3331234667")) {
            System.out.println("Tel: "+ t2);
        }
        
        
        // MAIN CON MENU
        while (true) {
            Scanner in = new Scanner(System.in);
            System.out.print("\033[H\033[2J");  
            System.out.flush(); 
            System.out.println("************************************");
            System.out.println("******* MENU FUNZIONI **************");
            System.out.println("************************************\n");
            System.out.println("1) Visualizza elenco telefonate ");
            System.out.println("2) Inserisci nuova telefonata ");
            System.out.println("X) Exit ");
            
            String ch = in.nextLine();
            if (ch.equals("X")) {
                break;
            }
            
            if (ch.equals("1")) {
                System.out.println("Lista telefonate:");
                for (Telefonata t2 : s.getTelefonate()) {
                    System.out.println("Tel: "+ t2);
                }
            }
            
            if (ch.equals("2")) {
                System.out.println("Inserimento nuova telefonata:");
                System.out.print("Inserisci il numero : "); String n = in.nextLine();
                System.out.print("Inserisci l'ora : "); String o = in.nextLine();
                System.out.print("Inserisci la durata : "); int d = in.nextInt();
                s.addTelefonata(new Telefonata(n,o,d));
            }

            System.out.println("Enter to continue...");
            ch = in.nextLine();
        }
        
        
    }
    
}
