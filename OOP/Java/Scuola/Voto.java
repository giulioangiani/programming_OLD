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
public class Voto {
    
    private String materia;
    private String data;
    private float valutazione = 0;
    private String tipo = "";
    
    // Realizzo il PATTERN dell'associazione 1 a N
    // fra Voto e Studente
    private Studente studente;
    
    
    /**
     * Costruttore:
     * @param materia materia del voto
     * @param data giorno del voto
     */
    public Voto(String materia, String data) {
        this.materia = materia;
        this.data = data;
    }
    
    /**
     * Costruttore:
     * @param materia materia del voto
     * @param data giorno del voto
     * @param valutazione valore del voro
     * @param tipo tipo del voto
     */
    public Voto(String materia, String data, float valutazione, String tipo) {
        this.materia = materia;
        this.data = data;
        this.valutazione = valutazione;
        this.tipo = tipo;
    }

    /**
     * Restituisce la materia del voto
     * @return string materia
     */
    public String getMateria() {
        return this.materia;
    }
    
    /**
     * Restituisce la data del voto
     * @return string data
     */
    public String getData() {
        return this.data;
    } 
    
    /**
     * Valorizza la valutazione
     * @param v valutazione
     */
    public void setValutazione(float v) {
        this.valutazione = v;
    }
    
        
    /**
     * Restituisce il valore della valutazione
     * @return string tipo
     */
    public float getValutazione() {
        return this.valutazione;
    }

    /**
     * Valorizza il tipo di valutazione
     * @return int classe
     */
    public void setTipo(String t) {
        this.tipo = t;
    } 
    
    /**
     * Restituisce il tipo del voto
     * @return string tipo
     */
    public String getTipo() {
        return this.tipo;
    }
    
    // Realizzo il PATTERN dell'associazione 1 a N
    // fra Voto e Studente
    
    /**
     * Restituisce l'oggetto Studente proprietario del voto
     * @return Studente
     */
    public Studente getStudente() {
        return studente;
    }


    /**
     * Rappresentazione stringa del voto
     * @return 
     */
    @Override
    public String toString() {
      return "[Voto: " + this.getMateria() + " " + this.getValutazione() + " (" + this.getData() + ") ]";  
    }
    
    
    /**
     * Valorizza lo Studente del voto
     * @param studente 
     */
    public void setStudente(Studente studente) {
        this.studente = studente;
    }
  
}
