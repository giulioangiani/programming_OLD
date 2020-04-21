/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gestionefile;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author giulio
 */
public class Main_file_esercizi_semplici {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        /*  Es.1
            Leggere da input nome e cognome di un utente e scriverlo sul file 
            "utenti.txt"
        */
        Scanner s = new Scanner(System.in);
        String n;
        String c;
        if (true) {
            String filename = "utenti.txt";
            File file = new File(filename); // non permette né lettura né scrittura
            FileWriter fw = new FileWriter(file, true); // aperto in append
            System.out.print("Inserisci il nome :");
            n = s.nextLine();
            fw.write("Nome: " + n + "\n");
            System.out.print("Inserisci il cognome :");
            c = s.nextLine();
            fw.write("Cognome: " + c + "\n");
            fw.close();
        }
        
        if (false) {
            /*  Es.2
                Leggere parole e scriverle sul file "parole.txt" finché l'utente non 
                preme solo invio
            */

            BufferedWriter bw2 = new BufferedWriter(new FileWriter(new File("parole.txt")));
            n = "-";
            while (!n.equals("")) {
                System.out.print("Inserisci parola [invio per terminare] :");
                n = s.nextLine();
                if (!n.equals("")) bw2.write(n + "\n");
            }
            bw2.flush();
            bw2.close();
        }


        if (false) {
            /*  Es.3
                Leggere parole e aggiungerle al file "parole.txt" finché l'utente non 
                preme solo invio
            */

            BufferedWriter bw3 = new BufferedWriter(new FileWriter(new File("utenti.txt"), true));
            n = "-";
            while (!n.equals("")) {
                System.out.print("Inserisci parola [invio per terminare] :");
                n = s.nextLine();
                if (!n.equals("")) bw3.write(n + "\n");
            }
            bw3.flush();
            bw3.close();
        }

    }
    
}
