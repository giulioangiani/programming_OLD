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
public class Studente {
    
    private String nome;
    private String cognome;
    private int classe = 0;
    private char sezione = 'X';
    private int matricola = 0;
    
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
     * @param c 
     */
    public void setClasse(int c) {
        this.classe = c;
    }
    
    /**
     * Restituisce la classe dello studente
     * @return int classe
     */
    public int getClasse() {
        return this.classe;
    } 
    
    /**
     * Valorizza la sezione dello studente
     * @param c 
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
    
    
}
