/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rettangolo;

/**
 *
 * @author angianig
 */
public class Main_Test_Rettangolo {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Rettangolo rett= new Rettangolo((float) 5.5, 10);   //Dichiarazione della variabile rett di tipo Rettangolo con 2 parametri che rappresentano base e altezza
        System.out.println(rett.calcolaArea());
        
        Quadrato quadrato2= new Quadrato((float) 4.2);      //Dichiarazione della variabile quadrato di tipo Quadrato con un parametro che rappresenta il lato
        System.out.println(quadrato2.calcolaArea());
        
        System.out.println(quadrato2.getLato());
        
        Rettangolo r[] = new Rettangolo[5];
        r[0]=rett;
        r[1]=quadrato2;
        
        Quadrato q[] = new Quadrato[2];
        q[0]=(Quadrato) rett;
        
    }
    
}
