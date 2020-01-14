/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lanciodeidadi;

/**
 *
 * @author giulio
 * Dado a sei facce
 */
public class Dado {
    
    /**
     * Costruttore: non riceve parametri
     */
    public Dado() {}

    /**
     * Restituisce un numero intero casuale da 1 a 6
     */
    public int lancia() {
        return (int)(Math.random()*6) + 1;
    }
    
}
