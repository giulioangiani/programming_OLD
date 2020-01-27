/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package geometria;

/**
 *
 * @author giulio
 */
public class Quadrato {

    private final double lato;

    /**
     * Costruttore di classe
     * @param L indica il lato del quadrato
     */
    public Quadrato (double L) {
        this.lato = L;
    }
    
    /**
     * 
     * @return double area del quadrato di lato L
     */
    public double area() {
        return Math.pow(this.lato, 2);
    }

    public double getDiagonale() {
        return this.lato*Math.sqrt(2);
    }
    
}
