/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lanciodeidadi;

/**
 *
 * @author giulio
 */
public class DadoTanteFacce {
    
    private int facce = 0;
    
    /**
     * Costruttore: riceve come unico parametro il numero di facce del dado
     * 
     * @param numerofacce numero di facce del dado
     */
    public DadoTanteFacce(int numerofacce) {
        this.facce = numerofacce;
    }
    
    /**
     * Restituisce un numero intero casuale da 1 a numero di facce indicato nel costruttore
     * @return int numero estratto
     */
    public int lancia() {
        return (int)(Math.random()*this.facce) + 1;
    }
    
}
