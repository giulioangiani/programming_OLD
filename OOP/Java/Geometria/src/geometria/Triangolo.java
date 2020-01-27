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
public class Triangolo {

    private double base=0;
    private double altezza=0;

    private double A=0;
    private double B=0;
    private double C=0;

    /**
     * Costruttore di classe (con base e altezza)
     * @param B indica la base del rettangolo
     * @param H indica l'altezza del rettangolo
     * @throws Fatal_Error se B o H sono non positivi
     */
    public Triangolo (double B, double H) throws Exception {
        if (B<=0) throw new Exception("Fatal Error: Base non puo' essere negativa o nulla");
        if (H<=0) throw new Exception("Fatal Error: Altezza non puo' essere negativa o nulla");
        this.base = B;
        this.altezza = H;
    }

    /**
     * Costruttore di classe (con lunghezza di tutti e tre i lati)
     * @param A indica la lunghezza del lato a
     * @param B indica la lunghezza del lato b
     * @param C indica la lunghezza del lato c
     * @throws Fatal_Error i dati non sono coerenti
     */
    public Triangolo (double A, double B, double C) throws Exception {
        
        if (A<=0) throw new Exception("Fatal Error: A non puo' essere negativa o nulla");
        if (B<=0) throw new Exception("Fatal Error: B non puo' essere negativa o nulla");
        if (C<=0) throw new Exception("Fatal Error: B non puo' essere negativa o nulla");
        
        if (A>=B+C) throw new Exception("Fatal Error: A deve essere minore della somma di B e C");
        if (B>=A+C) throw new Exception("Fatal Error: B deve essere minore della somma di A e C");
        if (C>=A+B) throw new Exception("Fatal Error: C deve essere minore della somma di A e B");

        // se sono qui i dati sono coerenti
        
        this.A = A;
        this.B = B;
        this.C = C;
    }
    
    /**
     * Restituisce l'area del triangolo
     * @return double area del triangolo 
     */
    public double area() {
        // se sono stati settate base e altezza nel costruttore
        if ((this.base > 0 && this.altezza>0)) return this.base*this.altezza;
        // altrimenti calcolo con Erone
        else {
            double p = (this.A+this.B+this.C)/2;
            return Math.sqrt(p*(p-this.A)*(p-this.B)*(p-this.C));
        }
    }
    
}
