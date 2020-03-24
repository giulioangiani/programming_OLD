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
    
    public IpAddress(String ip, int bitRete) throws TooManyNetmaskBitsException, IPFormatNotCorrectException {
        
        if (bitRete > 32) throw new TooManyNetmaskBitsException();
        // aggiungere il controllo del numero minimo di bit di rete
        
        // controllo formale dell'ip
        // ip deve essere formato da 4 numeri compresi
        // fra 0 a 255 e divisi da un punto
        // String[] ottetti = ip.split("1");
        String[] ottetti = ip.split("\\.");
        if (ottetti.length != 4) throw new IPFormatNotCorrectException();
        
        // aggiungere controllo al valore degli ottetti
        
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
