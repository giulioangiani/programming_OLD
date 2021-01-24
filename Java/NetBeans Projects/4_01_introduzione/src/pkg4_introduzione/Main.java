package pkg4_introduzione;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class Main {
  
    public static void main(String[] args) {
        String[] sp = null;
        int nrighe = 0;
        int parole = 0;
        String[] p = null;
        int somma = 0;
        int renzo = 0;
        int lucia = 0;
        
        HashMap<String, Integer> contaparole = new HashMap<String, Integer>();
        contaparole.put("Renzo", 10);
        contaparole.put("Lucia", 20);
        System.out.println("contaparole = " + contaparole);
        
        //// LETTURA DI UN FILE DI TESTO
        try {
            // prova a fare questa istruzione
            String line = null;
           
            BufferedReader br = new BufferedReader(new FileReader("I_promessi_sposi.txt"));
            while ((line = br.readLine()) != null) {
                // System.out.println("RIGA : " + line);
                if (!line.isEmpty()) {
                    nrighe ++;
                    p = line.split(" ");
                //    System.out.println(p.length);
                    parole += p.length;
                    try {
                        somma += Integer.parseInt(line);
                    }
                    catch(Exception e) 
                    {}
                    
                    for (int i=0; i<p.length; i++) {
//                        if (p[i].equals("Renzo")) renzo++;
                        if (p[i].contains("Renzo")) renzo++;
                        if (p[i].contains("Lucia")) lucia++;
                        
                        String singolaparola = p[i];
                        if (contaparole.containsKey(singolaparola)) {
                            int v = contaparole.get(singolaparola);
                            v++;
                            contaparole.put(singolaparola, v);
                        }
                        else {
                            contaparole.put(singolaparola, 1);
                        }
                        
                    }
                    
                }
                    
            }
             
        }
        catch (Exception err) {
            // se ci sono problemi finisce qui 
            // invece di chiudere l'applicazione
            System.out.println("Oops! E' successo un errore imprevisto!");
            err.printStackTrace();
        }
        System.out.println("Righe :  " + nrighe);
        System.out.println("Parole :  " + parole);
        System.out.println("Somma :  " + somma);
        System.out.println("Renzo :  " + renzo);
        System.out.println("Lucia :  " + lucia);
        System.out.println(contaparole.size());
        
   }
    


}
