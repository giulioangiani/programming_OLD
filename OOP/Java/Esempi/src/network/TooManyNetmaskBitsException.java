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
public class TooManyNetmaskBitsException extends Exception {
    
    public TooManyNetmaskBitsException() {
        super("Too many network bits in netmask!");
    }
    
}
