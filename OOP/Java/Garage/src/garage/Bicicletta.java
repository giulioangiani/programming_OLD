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
public class Bicicletta extends Veicolo {
    
    private String tipologiabici;
    private boolean cestino = false;
    
    public Bicicletta() {}
    
    public String getTipologiaBici() {
        return this.tipologiabici;
    }

    public void setTipologiaBici(String n) {
        this.tipologiabici = n;
    }    

    public boolean hasCestino() {
        return this.cestino;
    }

    public void addCestino() {
        this.cestino = true;
    }        

    public void removeCestino() {
        this.cestino = false;
    }        


    @Override
    public String toString() {
        return "Bici " + this.getMarca() + " " + this.getMatricola() +  " : tipologia " + this.tipologiabici + " : Cestino " + this.hasCestino();
    }
    
    public boolean equals(Bicicletta b) {
        return (b.getMatricola().equals(this.getMatricola()));
    }
}
