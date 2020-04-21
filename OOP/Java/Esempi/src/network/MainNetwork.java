/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package network;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author giulio
 */
public class MainNetwork {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        

        
        IpAddress ip = null;
        try {
            ip = new IpAddress("192.168.1.121", 24); // 192.168.1.1/24
        } catch (TooManyNetmaskBitsException ex) {
            //System.out.println(ex.getMessage());
            System.out.println("Hai messo troppi bit di rete ! ");
            //System.out.println("ErrorCode:1"); 
        } catch (IPFormatNotCorrectException ex) {
            //System.out.println(ex.getMessage());
            System.out.println("Il formato IP non è corretto");
        }
        System.out.println("IP = " + ip);

        
        IpAddress ip2 = null;
        try {
            ip2 = new IpAddress("192.168.1.1", 50);
        } catch (Exception ex) {
            System.out.println("Errore in IP2 : " + ex.getMessage());
        }
        System.out.println("IP2 = " + ip2);

        IpAddress ip3 = null;
        try {
            ip3 = new IpAddress("192.122.5", 24);
        } catch (Exception ex) {
            System.out.println("Errore in IP3 : " + ex.getMessage());
        }
        System.out.println("IP3 = " + ip3);

        System.out.println("bc = " + ip.getBroadcast());

    
    
    }
    
}
