/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package garage;

import java.util.ArrayList;

/**
 *
 * @author giulio
 */
public class Garage {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        // instanza di Veicolo
        Veicolo v = new Veicolo();
        System.out.println("Velocita di v = " + v.getVelocita());
        v.setVelocita(50);
        System.out.println("Velocita di v = " + v.getVelocita());
        v.accelera(10);
        System.out.println("Velocita di v = " + v.getVelocita());
        v.decelera(5);
        System.out.println("Velocita di v = " + v.getVelocita());
        v.decelera(30);
        System.out.println("Velocita di v = " + v.getVelocita());
        v.decelera(30);
        System.out.println("Velocita di v = " + v.getVelocita());
        v.decelera(30);
        System.out.println("Velocita di v = " + v.getVelocita());
        
        System.out.println("Costo Sosta = " + v.getCostoTotaleSosta());
        v.setCostoOrario(3);
        v.setMinutiSosta(120);
        System.out.println("Costo Sosta = " + v.getCostoTotaleSosta());
        
        // instanza di Automobile
        Automobile a = new Automobile(180, "Utilitaria");
        System.out.println("Velocita di a = " + a.getVelocita());
        a.setVelocita(50);
        System.out.println("Costo Sosta = " + a.getCostoTotaleSosta());
        a.setCostoOrario(3);
        a.setMinutiSosta(120);
        System.out.println("Costo Sosta = " + a.getCostoTotaleSosta());
        System.out.println("Velocita massima = " + a.getVelocitaMassima());
        System.out.println("Tipologia = " + a.getTipologia());
        
        a.accelera(100);
        System.out.println("Velocita di a = " + a.getVelocita());
        a.accelera(100);
        System.out.println("Velocita di a = " + a.getVelocita());
        System.out.println("Max passeggeri di a = " + a.getMaxPasseggeri());
        a.setMaxPasseggeri(5);
        System.out.println("Max passeggeri di a = " + a.getMaxPasseggeri());
        a.setMarca("Fiat");
        a.setMatricola("AB102XY");
        System.out.println("a = " + a);
        

        Automobile b = new Automobile(220, "Fuoristrada");
        b.setMatricola("CX098FR");
        System.out.println("A == B ? " + a.equals(b));

        Bicicletta bici = new Bicicletta();
        bici.addCestino();
        bici.setTipologiaBici("Citybike");
        System.out.println("bici ha cestino ? " + bici.hasCestino());
        bici.removeCestino();
        System.out.println("bici ha cestino ? " + bici.hasCestino());
        bici.setMarca("Bianchi");
        bici.setMatricola("BC0009");
        System.out.println("Bici = " + bici);
        bici.addCestino();
        System.out.println("Bici = " + bici);

        System.out.println("A == B ? " + a.equals(b));
        System.out.println("A == Bici ? " + a.equals(bici));
        
        System.out.println("**************************************");
        
        ArrayList<Veicolo> garage = new ArrayList<>();
        garage.add(v);
        garage.add(a);  // auto
        garage.add(b);  // auto
        garage.add(bici); // bici
        
        for (Veicolo tmp : garage) {
            
            if (tmp instanceof Bicicletta) {
                System.out.println("veicolo " + tmp);
            }
        }
              
    }
    
}
