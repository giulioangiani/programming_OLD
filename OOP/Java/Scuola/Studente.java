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
public class Studente {
    
    private String nome;
    private String cognome;
    private int classe = 0;
    private char sezione;
    private int matricola = 0;
    
    // Realizzo il PATTERN dell'associazione 1 a N
    // fra Voto e Studente
    private ArrayList<Voto> voti = new ArrayList<>();

    
    /**
     * Costruttore:
     * @param n nome dello studente
     * @param c cognome dello studente
     */
    public Studente(String n, String c) {
        this.nome = n;
        this.cognome = c;
    }
    
    /**
     * Restituisce il nome dello studente
     * @return string nome
     */
    public String getNome() {
        return this.nome;
    }
    
    /**
     * Restituisce il cognome dello studente
     * @return string cognome
     */
    public String getCognome() {
        return this.cognome;
    } 
    
    /**
     * Valorizza la matricola dello studente
     * @param m 
     */
    public void setMatricola(int m) {
        this.matricola = m;
    }
    
    /**
     * Restituisce la matricola dello studente
     * @return int matricola
     */
    public int getMatricola() {
        return this.matricola;
    } 
    
    /**
     * Valorizza la classe dello studente
     * @param int c 
     */
    public void setClasse(int c) {
        this.classe = c;
    }
    
    
    /**
     * Valorizza la sezione dello studente
     * @param char c 
     */
    public void setSezione(char s) {
        this.sezione = s;
    }
    
    /**
     * Restituisce la sezione dello studente
     * @return char sezione
     */
    public char getSezione() {
        return this.sezione;
    } 

    /**
     * Restituisce la classe dello studente
     * @return int classe
     */
    public int getClasse() {
        return this.classe;
    } 
    
    @Override
    public String toString() {
      return "[Studente: " + this.cognome + " " + this.nome + "]";  
    }

    
    // Realizzo il PATTERN dell'associazione 1 a N
    // fra Voto e Studente
    /**
     * Aggiunge un oggetto Voto 
     * @param Voto v
     */
    public void addVoto(Voto v) {
        // questa informazione potrebbe essere passata anche direttamente
        // nel metodo setStudente() della classe Voto 
        // senza metterlo in questa posizione
        // ma qui è meglio perché evito di doverlo fare ogni volta 
        // manualmente
        this.voti.add(v);
        v.setStudente(this);
    }
    
    /**
     * Restituisce la struttura contenente tutti i voti dello studente
     * @return ArrayList<Voto>
     */
    public ArrayList<Voto> getVoti() {
        return this.voti;
    }
    
    
    public float getMediaTotale() {
        float somma = 0;
        int cont = 0;
        for (Voto x : this.getVoti()) {
            somma = somma + x.getValutazione();
            cont++;
        }
        float media = somma/cont;        
        return media;
    }

    public float getMediaMateria(String materia) {
        float somma = 0;
        int cont = 0;
        for (Voto x : this.getVoti()) {
            if (materia == x.getMateria()){
                somma = somma + x.getValutazione();
                cont++;
            }
        }
        return somma/cont;  // thanks to Camilla      
    }
    
    
}
