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
public class Quadrato extends Rettangolo {
    
    /*public Quadrato(float base, float altezza) {
        super(base, altezza);
    }*/
    
    public Quadrato(float lato){
        super(lato, lato);
    }
    
    public float getLato(){
        return this.base;
    }
}
