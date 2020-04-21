/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package network;

/**
 *
 * @author giulio
 */
public class IpAddress {
    
    private String ip = "0.0.0.0";
    private int numeroBitRete;
    private int numeroBitHost;
    private int[] ottetti = new int[4];
    
    public IpAddress(String ip, int bitRete) throws TooManyNetmaskBitsException, IPFormatNotCorrectException {
        
        if (bitRete > 32) throw new TooManyNetmaskBitsException();
        // aggiungere il controllo del numero minimo di bit di rete
        
        // controllo formale dell'ip
        // ip deve essere formato da 4 numeri compresi
        // fra 0 a 255 e divisi da un punto
        // String[] ottetti = ip.split("1");
        String[] octets = ip.split("\\.");
        if (octets.length != 4) throw new IPFormatNotCorrectException();
        // aggiungere controllo al valore degli ottetti
        
        for (int i = 0; i<4; i++) {
            this.ottetti[i] = Integer.parseInt(octets[3-i]);
        }
        this.ip = ip;
        this.numeroBitRete = bitRete;
        this.numeroBitHost = 32-bitRete;
    }
    
    public String toString() {
        // ritorna in formato CIDR
        return this.ip + "/" + this.numeroBitRete;
    }
    
    public String getBroadcast() {
        // restituisce l'ip di broadcast della rete di appartenza
        
        // da ottetti a binario
        int dec = this.ottetti[0] + this.ottetti[1]*256 + this.ottetti[2]*256*256 + this.ottetti[3]*256*256*256;
        String bin = Integer.toBinaryString(dec);
        // padding
        String octect =  bin;
        for (int i=0; i<32-bin.length();i++) octect = "0"+octect;
        System.out.println(octect);
        
        
       // int foo = Integer.parseInt("11001001", 2);
       // System.out.println("foo = " + foo);
        


        
        return "0.0.0.0";
    }
    
    public String getNetworkAddress() {
        // restituisce l'ip di rete della rete di appartenza
        return "0.0.0.0";
    }
    
    public int ampiezzaRete() {
        // restituisce l'ampiezza della rete di appartenza
        return 256;
    }

}
