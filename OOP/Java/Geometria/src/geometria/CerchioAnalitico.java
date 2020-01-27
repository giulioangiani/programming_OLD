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
public class CerchioAnalitico {
 
    private double radius = 1;
    private double x = 0;
    private double y = 0;
    
    /**
     * Costruttore di classe
     * @throws Fatal_Error se r è minore o uguale a zero
     * @param x indica la coordinata x del centro
     * @param y indica la coordinata y del centro
     * @param r indica il raggio del cerchio
     */
    public CerchioAnalitico(double x, double y, double r) throws Exception {
        if (r<=0) throw new Exception("Fatal Error: Radius must be positive");
        this.radius = r;
        this.x = x;
        this.y = y;
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
    
    /**
     * Calcola la distanza del cerchio dall'origine del piano cartesiano
     * @return valore della distanza del cerchio dall'origine 
     */
    public double distanzaDaOrigine() {
        /* uso pitagora per calcolare la distanza del
           centro dall'origine
           Poi sottraggo il valore del raggio
        */
        double distanzaCentroOrigine = Math.sqrt(x*x + y*y);
        return distanzaCentroOrigine-this.radius;
    }
    
    
}
