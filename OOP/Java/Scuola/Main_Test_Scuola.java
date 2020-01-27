/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package scuola;

import java.util.ArrayList;

/**
 *
 * @author giulio
 */
public class Main_Test_Scuola {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Test classi Studente e Voto
        Studente s1 = new Studente("Giulio", "Angiani");
        Studente s2 = new Studente("Alessandro", "Muzzini");
        s1.setClasse(4);
        s1.setSezione('E');
        s2.setClasse(4);
        s2.setSezione('C');
        s1.setMatricola(1001);
        s2.setMatricola(1002);

        System.out.println("Studente #1\n" + s1.getNome() + " " + s1.getCognome());
        System.out.println("Matricola : " + s1.getMatricola());
        System.out.println("Classe    : " + s1.getClasse());
        System.out.println("Sezione   : " + s1.getSezione());
        System.out.println("*******************************************");
        System.out.println("Studente #2\n" + s2.getNome() + " " + s2.getCognome());
        System.out.println("Matricola : " + s2.getMatricola());
        System.out.println("Classe    : " + s2.getClasse());
        System.out.println("Sezione   : " + s2.getSezione());

        System.out.println("*******************************************");
        Voto v = new Voto("Italiano", "2020/01/15");
        v.setTipo("Scritto");
        v.setValutazione((float) 7.5);
        // aggancio il voto agli studenti
        //v.setStudente(s1);
        s1.addVoto(v);

        Voto v2 = new Voto("Inglese", "2020/01/24");
        v2.setTipo("Orale");
        v2.setValutazione((float) 8);
        // aggancio il voto allo studente
        s2.addVoto(v2);

        Voto v3 = new Voto("Matematica", "2020/01/23");
        v3.setTipo("Scritto");
        v3.setValutazione((float) 6.5);
        // aggancio il voto allo studente
        s2.addVoto(v3);

        System.out.println("Voti di " + s1);
        System.out.println(s1.getVoti());

        System.out.println("Voti di " + s2);
        System.out.println(s2.getVoti());

        // recupero la media totale dei voti
        System.out.println("media totale = " + s2.getMediaTotale());
       
        // aggancio altri voti di italiano con un nuovo costruttore
        // che recepisce tutti i parametri del voto
        s2.addVoto(new Voto("Italiano", "2020/01/15", (float)8.5, "Scritto"));
        s2.addVoto(new Voto("Italiano", "2020/01/18", (float)7.25, "Orale"));
        s2.addVoto(new Voto("Italiano", "2020/01/25", (float)7.25, "Pratico"));

        // recupero la media totale dei voti per materia
        System.out.println("media Mate = " + s2.getMediaMateria("Matematica"));
        System.out.println("media Italiano = " + s2.getMediaMateria("Italiano"));

    }

}


