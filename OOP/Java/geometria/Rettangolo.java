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
public class Rettangolo {

    private final double base, altezza;

    /**
     * Costruttore di classe
     * @param B indica la base del rettangolo
     * @param H indica l'altezza del rettangolo
     * @throws Fatal_Error se B o H sono non positivi
     */
    public Rettangolo (double B, double H) throws Exception {
        if (B<=0) throw new Exception("Fatal Error: Base non puo' essere negativa o nulla");
        if (H<=0) throw new Exception("Fatal Error: Altezza non puo' essere negativa o nulla");
        this.base = B;
        this.altezza = H;
    }
    
    /**
     * 
     * @return double area del quadrato di lato L
     */
    public double area() {
        return this.altezza*this.base;
    }

    /**
     * 
     * @return double lunghezza della diagonale del quadrato di lato L
     */
    public double getDiagonale() {
        return Math.sqrt(this.altezza*this.altezza + this.base*this.base);
    }
    
}
