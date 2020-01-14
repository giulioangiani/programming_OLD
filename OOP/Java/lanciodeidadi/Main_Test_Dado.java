/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lanciodeidadi;
import java.util.HashMap;
/**
 *
 * @author giulio
 */
public class Main_Test_Dado {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Test istanza della classe Dado
        Dado d = new Dado();
        int estratto = d.lancia();
        System.out.println("Estratto " + estratto);
        System.out.println("**********************************************************");
        
        // Test statistica estrazione 1000 lanci di due dadi
        HashMap<Integer, Integer> h = new HashMap<>();
        
        for (int i=0; i<1000; i++) {
            int n1 = d.lancia();
            int n2 = d.lancia();
            int n = n1 + n2;
            if (!h.containsKey(n)) {
                h.put(n, 1);
            }
            else {
                int valorecorrente = h.get(n);
                valorecorrente++;
                h.put(n, valorecorrente);
            }
        }
        
        int totalelanci = 0;
        for (HashMap.Entry<Integer, Integer> entry : h.entrySet()) {
            int k = entry.getKey();
            int v = entry.getValue();
            
            // Generazione istogramma con carattere #
            
            // padded output per visualizzazione corretta dell'istogramma
            System.out.print( String.format("N. %1$2s) Volte: %2$3s : ", k, v) );
            
            // divido per 2 per evitare righe troppo lunghe
            for(int i=0; i<v/2; i++) {
                System.out.print("#");
            }
            System.out.println();
        }
        System.out.println("*************************************");
    }
}
