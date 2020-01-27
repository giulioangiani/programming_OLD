/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matematica;

/**
 *
 * @author giulio
 */
public class NumeroRazionale {

    private int numeratore;
    private int denominatore;
 
    public NumeroRazionale(int num, int den) throws Exception {
        if (den == 0) throw new Exception("Il denominatore non può essere zero");
        this.numeratore = num;
        this.denominatore = den;
    }
    
    public float realValue() {
        return (float)this.numeratore/this.denominatore;
    }

    public NumeroRazionale inverso() throws Exception {
        return new NumeroRazionale(this.denominatore, this.numeratore);
    }
    
}
