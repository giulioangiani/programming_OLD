/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package busflix;

/**
 *
 * @author giulio
 */
public class Abbonamento {
    
    private final String nome;
    private final float costo;
    
    public Abbonamento(String nome, float costo) {
        this.nome = nome;
        this.costo = costo;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public float getCosto() {
        return this.costo;
    }
    
    @Override
    public String toString() {
       return String.format("( Abbonamento: %s : Costo %.2f )", this.getNome(), this.getCosto());
    }    
    
}
