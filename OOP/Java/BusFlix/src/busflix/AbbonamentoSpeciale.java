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
public class AbbonamentoSpeciale extends Abbonamento {
    
    private final String docente;
    
    public AbbonamentoSpeciale(String nome, float costo, String docente) {
        super(nome, costo);
        this.docente = docente;
    }
    
    public String getDocente() {
        return this.docente;
    }

    @Override
    public String toString() {
       return String.format("( Abbonamento Speciale: %s - Docente %s : Costo %.2f )", this.getNome(), this.getDocente(), this.getCosto());
    }       
}
