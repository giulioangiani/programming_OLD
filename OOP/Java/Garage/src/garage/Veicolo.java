/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package garage;

/**
 *
 * @author giulio
 */
public class Veicolo {
    private String matricola;
    private String colore;
    private String marca;
    protected int velocita; // permette l'accesso all'attributo anche nelle classi derivate
    private int anno;
    private int ruote;
    private float costoOrario;
    private int minutiSosta = 0;
    
    
    public Veicolo() {}
    
    public void setMatricola(String p) {
        this.matricola = p;
    }
    public String getMatricola() {
        return this.matricola;
    }
    
    public void setColore(String p) {
        this.colore = p;
    }
    public String getColore() {
        return this.colore;
    }

    public void setMarca(String p) {
        this.marca = p;
    }
    public String getMarca() {
        return this.marca;
    }
    
    public void setVelocita(int p) {
        this.velocita = p;
    }
    public int getVelocita() {
        return this.velocita;
    }
    
    public void setAnno(int p) {
        this.anno = p;
    }
    public int getAnno() {
        return this.anno;
    }
    
    public void setRuote(int p) {
        this.ruote = p;
    }
    public int getRuote() {
        return this.ruote;
    }
    
    public void setMinutiSosta(int p) {
        this.minutiSosta = p;
    }
    public int getMinutiSosta() {
        return this.minutiSosta;
    }
      
    public void setCostoOrario(float p) {
        this.costoOrario = p;
    }
    public float getCostoOrario() {
        return this.costoOrario;
    }
      
    public float getCostoTotaleSosta() {
        //  l'importo totale della sosta: costo_orario*ore di sosta. 
        
        return this.costoOrario*this.minutiSosta/60;
    }      

    public void accelera(int kmh) {
        this.velocita = this.velocita + kmh;
    }          
    
    public void decelera(int kmh) {
        this.velocita = this.velocita - kmh;
        if (this.velocita < 0) this.velocita = 0;
    }          
}
