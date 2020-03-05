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
public class Automobile extends Veicolo {
    
    private final int VELOCITAMASSIMA;
    private final String TIPOLOGIA;
    private int maxPasseggeri = 2;
    
    public Automobile(int velocitamassima, String tipologia) {
        this.VELOCITAMASSIMA = velocitamassima;
        this.TIPOLOGIA = tipologia;
    }
    
    public int getVelocitaMassima() {
        return this.VELOCITAMASSIMA;
    }
    
    public String getTipologia() {
        return this.TIPOLOGIA;
    }

    public int getMaxPasseggeri() {
        return this.maxPasseggeri;
    }

    public void setMaxPasseggeri(int n) {
        this.maxPasseggeri = n;
    }

    @Override
    public void accelera(int kmh) {
        //this.velocita = this.velocita + kmh;
        super.accelera(kmh); // invocare il metodo della classe padre
        if (this.velocita > this.VELOCITAMASSIMA) this.velocita = this.VELOCITAMASSIMA;
    }      
    
    @Override
    public String toString() {
        return "Auto " + this.getMarca() + " " + this.getMatricola() +  " : tipologia " + this.TIPOLOGIA + " [max " + this.maxPasseggeri + " persone]";
    }
    
//    @Override
//    public boolean equals(Object b) {
//        return (((Veicolo)b).getMatricola().equals(this.getMatricola()));
//    }

    public boolean equals(Automobile b) {
        return (b.getMatricola().equals(this.getMatricola()));
    }    
}
