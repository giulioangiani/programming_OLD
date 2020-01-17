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
public class Cerchio {

    private double radius = 1;
    
    
    /**
     * Costruttore di classe
     * @throws Fatal_Error se r è minore o uguale a zero
     * @param r indica il raggio del cerchio
     */
    public Cerchio(double r) throws Exception {
        if (r<=0) throw new Exception("Fatal Error: Radius must be positive");
        this.radius = r;
    }

    /**
     * Calcola l'area del cerchio di raggio r specificato nel costruttore
     * @return valore dell'area del cerchio 
     */
    public double area() {
        return this.radius*this.radius*Math.PI;
    }

    /**
     * Calcola l'area della circonferenza di raggio r specificato nel costruttore
     * @return valore della circonferenza del cerchio 
     */
    public double circonferenza() {
        return this.radius*2*Math.PI;
    }
    
}
