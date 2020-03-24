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
class IPFormatNotCorrectException extends Exception {

    public IPFormatNotCorrectException() {
        // invoca il costrutture Exception(String message) 
        // della classe padre Exception
        // passandogli la stringa da visualizzare nel getMessage()
        super("Ip format is not correct!");
    }
    
}
