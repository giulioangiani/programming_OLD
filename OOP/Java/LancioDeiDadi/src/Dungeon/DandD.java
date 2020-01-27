/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Dungeon;

import lanciodeidadi.*;
/**
 *
 * @author giulio
 */
public class DandD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        Dado d = new Dado();
        DadoTanteFacce dd = new DadoTanteFacce(20);
        
        System.out.println("Dadone:"+dd.lancia());
        
    }
    
}
