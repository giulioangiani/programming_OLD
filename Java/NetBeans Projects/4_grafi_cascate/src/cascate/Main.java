package cascate;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class Main {

    public static ArrayList<Integer> maxPortataPath(int g[][], int N, int s, int d) {
        ArrayList<Integer> path = new ArrayList<>();
        if (s==d) return path;

        for (int i=1; i<=N; i++) {
            if ((i==d) && (g[s][i] > 0)) {
                path.add(i);
                return path;
            }
        }


        int max = -1;
        for (int i=1; i<=N; i++) {
            if (g[s][i] > 0) {
                int p = g[s][i] + maxPortata(g, N, i, d);
                if (p>max) {
                    max = p;
                    path = maxPortataPath(g, N, i, d);
                    path.add(i);
                }
            }
        }
        return path;
    }

    
    public static int maxPortata(int g[][], int N, int s, int d) {
        //System.out.println("DA " + s + " a " + d);
        if (s==d) {
            System.out.println("  >> nodo target : " + s);
            return 0;
        }

        for (int i=1; i<=N; i++) {
            if ((i==d) && (g[s][i] > 0))
                return g[s][i];
        }

        int max = -1;
        for (int i=1; i<=N; i++) {
            if (g[s][i] > 0) {
        //        System.out.println(" arco da " + s + " " + i + " " + g[s][i]);
                int nextpath = maxPortata(g, N, i, d);
                if (nextpath > 0) {
                    int p = g[s][i] + nextpath;
                    if (p>max) {
        //                System.out.println("Aggiorno Max " + s + "->" + d + " : " + nextpath);
                        max = p;
                    }
                }
            }
        }
//        if (max == -1 ) System.out.println("  << no succ per " + s + " " + d);
        return max;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        int G[][] = null;
        
        // TODO code application logic here
        // prova a fare questa istruzione
        String line = null;

        BufferedReader br = new BufferedReader(new FileReader("cascate.csv"));
        int N = Integer.parseInt(br.readLine());
        //System.out.println("N="+N);
        // definisco il grafo
        G = new int[N+1][N+1];
        while ((line = br.readLine()) != null) {
        //    System.out.println(">> " + line);
            String[] info = line.split(",");
            int nodopartenza = Integer.parseInt(info[0]);
            int nodoarrivo = Integer.parseInt(info[1]);
            int peso = Integer.parseInt(info[2]);
            G[nodopartenza][nodoarrivo] = peso;
        }

        /*
        // Stampa della matrice di adiacenza
        for (int[] r : G) {
            for (int c : r) {
                System.out.print(String.format("%02d ", c));
            }
            System.out.println();
        }    

        */
        
        int portatamassima = -1;
        int pozzomassimo = 0;
        ArrayList<Integer> percorsomassimo = null;

        for (int pozzo : new int[]{7,8,9,10} ) {
            int maxportata = maxPortata(G, N, 1, pozzo);
            ArrayList<Integer> maxportatapath = maxPortataPath(G, N, 1, pozzo);
            maxportatapath.add(1);
            if (maxportata > portatamassima) {
                Collections.reverse(maxportatapath);
                pozzomassimo = pozzo;
                portatamassima = maxportata;
                percorsomassimo = maxportatapath;
            }
                    
        //    System.out.println("Max portata per " + pozzo + " : " + maxportata + " : " + maxportatapath);
        }

        System.out.println("Massimo pozzo " + pozzomassimo);
        System.out.println("Portata massima per pozzo " + portatamassima);
        System.out.println("Percorso massimo " + percorsomassimo);
    }
    
}
