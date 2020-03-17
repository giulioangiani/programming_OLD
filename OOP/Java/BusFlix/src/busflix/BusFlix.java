/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package busflix;

import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author giulio
 */
public class BusFlix {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // test classe Utente
        
        Utente u1 = new Utente("Luigi", "Pirandello", "PRNLGU67H28A089U");
        System.out.println("U1 = " + u1);   // data di nascita di default
        u1.setDataNascita(new GregorianCalendar(1867, 5, 28));
        System.out.println("U1 = " + u1);
        

        Utente u2 = new Utente("Giacomo", "Leopardi", "LPRGCM98H29H211C", new GregorianCalendar(1798, 6, 29));
        System.out.println("U2 = " + u2);

        System.out.println("Credito di " + u2.getCognome() + " " + u2.getNome() + " = " + u2.getCredito());
        try {
            System.out.println("Ricarico -10");
            u2.ricarica(-10);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }

        System.out.println("Credito di " + u2.getCognome() + " " + u2.getNome() + " = " + u2.getCredito());
        try {
            System.out.println("Ricarico 7");
            u2.ricarica(7);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }


        System.out.println("Credito di " + u2.getCognome() + " " + u2.getNome() + " = " + u2.getCredito());
        try {
            System.out.println("Ricarico 20");
            u2.ricarica(20);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }
        System.out.println("Credito di " + u2.getCognome() + " " + u2.getNome() + " = " + u2.getCredito());

        System.out.println("U2 = " + u2);
        
        UtenteBus b1 = new UtenteBus("Giuseppe", "Ungaretti", "NGRGSP88B08E001H", new GregorianCalendar(1888, 1, 8));
        System.out.println("Utente Bus 1  = " + b1);
        try {
            b1.ricarica(10);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }
        System.out.println("Utente Bus 1  = " + b1);
        
        
        
        
        
        // test Abbonamento
        Abbonamento a1 = new Abbonamento("Matematica", (float) 30.0);
        System.out.println("Abbonamento a1 " + a1);
        Abbonamento a2 = new Abbonamento("Italiano", (float) 25.0);
        System.out.println("Abbonamento a2 " + a2);
        
        AbbonamentoSpeciale as1 = new AbbonamentoSpeciale("Sistemi", (float) 40.0, "Valentini Elisa");
        System.out.println("Abbonamento Speciale as1 " + as1);
        
        
        // collegamento Utenti-Abbonamenti
        try {
            u1.addAbbonamento(a1);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }
        
        try {
            u1.ricarica(50);
            u1.ricarica(50);
            System.out.println("Credito iniziale di u1 " + u1);
            u1.addAbbonamento(a1);
            u1.addAbbonamento(a2);
            System.out.println("Abbonamenti di " + u1.getCognome());
            for (Abbonamento tmp : u1.getAbbonamenti()) {
                System.out.println("  >> " + tmp);
            }
            System.out.println("Credito finale di u1 " + u1);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }

        
        
        try {
            u2.ricarica(20);
            System.out.println("Credito iniziale di u2 " + u2);
            u2.addAbbonamento(a1);
            System.out.println("Abbonamenti di " + u2.getCognome());
            for (Abbonamento tmp : u2.getAbbonamenti()) {
                System.out.println("  >> " + tmp);
            }
            System.out.println("Credito finale di u2 " + u2);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }


        try {
            // questo non deve succedere perché l'utente u2 non può sottoscrivere AbbonamentiSpeciali
            u2.ricarica(50);
            System.out.println("Altra ricarica di u2 : credito " + u2.getCredito());
            u2.addAbbonamento(as1);
            System.out.println("Dopo u2 : credito " + u2.getCredito());
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }

        // CASO UTENTE BUS
        System.out.println("=================================================");

        try {
            b1.ricarica(50);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }
        System.out.println("Credito iniziale di b1 " + b1);

        try {
            b1.addAbbonamento(a1);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }

        try {
            b1.addAbbonamento(a2);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }

        try {
            // questo invece deve essere permesso
            b1.addAbbonamento(as1);
        } catch (Exception ex) {
            System.out.println("Errore: " + ex.getMessage());
        }


        System.out.println("Abbonamenti di " + b1.getCognome());
        for (Abbonamento tmp : b1.getAbbonamenti()) {
            System.out.println("  >> " + tmp);
        }
        System.out.println("Credito finale di u1 " + b1);
        
        
        //// TEST DELLE FUNZIONALITA' DEL PROGRAMMA
        // 1 - stampare la lista di tutti gli abbonamenti disponibili con, se presente, il nome di chi tiene il corso
        // 2 - per ogni utente la lista dei suoi abbonamenti e il credito residuo
        // 3 - per ogni abbonamento il numero di utenti che l’hanno sottoscritto
        
        // STAMPA ABBONAMENTI
        // 1 - stampare la lista di tutti gli abbonamenti disponibili con, se presente, il nome di chi tiene il corso
        List<Abbonamento> abbonamentiBusFlix = new ArrayList<>();
        abbonamentiBusFlix.add(a1);
        abbonamentiBusFlix.add(a2);
        abbonamentiBusFlix.add(as1);
        System.out.println("\n\n==== STAMPA ABBONAMENTI BUSFLIX ====");
        for (Abbonamento a : abbonamentiBusFlix) {
            System.out.print(" - " + a.getNome()  + " : Costo " + a.getCosto());
            if (a instanceof AbbonamentoSpeciale) {
                System.out.println(" : Docente " + ((AbbonamentoSpeciale)a).getDocente());
            }
            else {
                System.out.print("\n");
            }
        }
        

        // STAMPA DATI UTENTI
        // 2 - per ogni utente la lista dei suoi abbonamenti e il credito residuo
        System.out.println("\n\n==== STAMPA DATI UTENTI BUSFLIX ====");
        List<Utente> utentiBusFlix = new ArrayList<>();
        utentiBusFlix.add(u1);
        utentiBusFlix.add(u2);
        utentiBusFlix.add(b1);
        for (Utente u : utentiBusFlix) {
            System.out.println(" - UTENTE : " + u.getNome() + " " + u.getCognome() + " [" + u.getCodiceFiscale() + "]");
            System.out.println("     Credito Residuo : € " + u.getCredito());

            // stampa abbonamenti di ogni singolo utente
            for (Abbonamento a : u.getAbbonamenti()) {
                System.out.print("          - Abbonato a : " + a.getNome()  + " : Costo " + a.getCosto());
                if (a instanceof AbbonamentoSpeciale) {
                    System.out.println(" : Docente " + ((AbbonamentoSpeciale)a).getDocente());
                }
                else {
                    System.out.print("\n");
                }
            }
        }

        // STAMPA DATI SOTTOSCRIZIONI DI OGNI ABBONAMENTO
        // 3 - per ogni abbonamento il numero di utenti che l’hanno sottoscritto
        System.out.println("\n\n==== STAMPA DATI SOTTOSCRIZIONI ====");
        AbbonamentoSpeciale as2 = new AbbonamentoSpeciale("MachineLearning", 70, "Steve Jobs");
        abbonamentiBusFlix.add(as2);
        HashMap<String, Integer> sottoscrizioni = new HashMap<>();
        for (Abbonamento a : abbonamentiBusFlix) {
            String nome_abbonamento = a.getNome();
            sottoscrizioni.put(nome_abbonamento, 0);    // all'inizio del ciclo sono 0
        }

        //sottoscrizioni.forEach((key,value) -> System.out.println("Abbonamento " + key + " => Sottoscrizioni " + value));

        for (Utente u : utentiBusFlix) {
            for (Abbonamento abboutente : u.getAbbonamenti()) {
                String nome_abbonamento_utente = abboutente.getNome();
                int sottoscrizioni_attuali = sottoscrizioni.get(abboutente.getNome()); // recupero il valore attuale
                sottoscrizioni_attuali++;  // lo incremento di 1
                sottoscrizioni.put(abboutente.getNome(), sottoscrizioni_attuali);
            }
        }
        
        sottoscrizioni.forEach((key,value) -> System.out.println("Abbonamento " + key + " => Sottoscrizioni " + value));
        
       
                
    }
    
}
