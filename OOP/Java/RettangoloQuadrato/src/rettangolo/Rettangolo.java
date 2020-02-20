/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rettangolo;

/**
 *
 * @author angianig
 */
public class Rettangolo {
    protected final float base;
    protected final float altezza;
    
    public Rettangolo(float base, float altezza){
        this.base=base;
        this.altezza=altezza;
    }

    public float getBase() {
        return base;
    }

    public float getAltezza() {
        return altezza;
    }
    
    public float calcolaArea(){
        return (this.altezza*this.base);
    }
}
