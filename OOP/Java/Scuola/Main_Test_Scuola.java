/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package scuola;

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
        System.out.println("Matricola : "  + s1.getMatricola());
        System.out.println("Classe    : "  + s1.getClasse());
        System.out.println("Sezione   : "  + s1.getSezione());
        System.out.println("*******************************************");
        System.out.println("Studente #2\n" + s2.getNome() + " " + s2.getCognome());
        System.out.println("Matricola : "  + s2.getMatricola());
        System.out.println("Classe    : "  + s2.getClasse());
        System.out.println("Sezione   : "  + s2.getSezione());
        
        System.out.println("*******************************************");
        Voto v = new Voto("Italiano", "2020/01/15");
        v.setTipo("Scritto");
        v.setValutazione((float) 7.5);
        System.out.println("Voto   : " + v.getMateria());
        System.out.println("Data   : " + v.getData());
        System.out.println("Valore : " + v.getValutazione());
        System.out.println("Tipo   : " + v.getTipo());
        
    }
    
}
