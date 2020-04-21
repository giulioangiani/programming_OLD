/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gestionefile;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author giulio
 */
public class Main_file {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException  {
        // TODO code application logic here
        
        String fname = "/tmp/dati.txt";
        
        File f = new File(fname);
        if (!f.exists()) {
            System.out.println("Il file " + f + " non esiste!");
            return;
        }        
        else {
            System.out.println("Path " + f.getAbsolutePath());
        }
        
        

        FileInputStream fr = new FileInputStream(fname);
        try {
            int ch = fr.read();
            System.out.println("Letto " + ch);
            char c = (char) ch;
            System.out.println("  >> " + c);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        
        
        try {
            int ch = fr.read();
            char c ;
            while (ch != -1) {
               c = (char) ch;
//               System.out.println(c  + " >> " + ch);   
               System.out.println(c);   
               ch = fr.read();
            }
        }   catch (IOException ex) {
            ex.printStackTrace();
        }
        
        fr.close();
        
        
        
        FileReader fread = new FileReader(fname);
        BufferedReader br = new BufferedReader(fread);
        try {
            String linea;
            while (( linea = br.readLine()) != null){
                System.out.println(">>  " + linea);
            }
            br.close();
        }
        catch(IOException e) {
            e.printStackTrace();
        }
        
        
        
        // scrivere su file di testo
        String filew = "/tmp/output.txt";
        try {
            File file = new File(filew);
            FileWriter fw = new FileWriter(file);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write("Oggi e' il 6 aprile!");
            bw.flush();
            bw.close();
        }
        catch(IOException e) {
            e.printStackTrace();
        }
        
        /*
        // scrivere file binari
        String output = "/tmp/output.dat";
        FileOutputStream fo = new FileOutputStream(output);
        DataOutputStream out = new DataOutputStream(fo);
        
        double[] prezzo = { 1.88, 1.75, 2.01 };
        int[] quantita = { 83, 78, 97 };
        String[] descrizione = { "Mele", "Pere", "Arance"};
        for (int i = 0; i < prezzo.length; i ++) {
            out.writeDouble(prezzo[i]);
            out.writeInt(quantita[i]);
            out.writeUTF(descrizione[i]);
        }
        out.close();
        */
    }
    
}
