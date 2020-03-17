/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package busflix;

import java.util.GregorianCalendar;

/**
 *
 * @author giulio
 */
public class UtenteBus extends Utente {
    
    public UtenteBus(String nome, String cognome, String codiceFiscale) {
        super(nome, cognome, codiceFiscale);
    }

    public UtenteBus(String nome, String cognome, String codiceFiscale, GregorianCalendar dn) {
        super(nome, cognome, codiceFiscale, dn);
    }

    @Override
    public void ricarica(int totale) throws java.lang.Exception {
        if (!Utente.RICARICHE_VALIDE.contains(totale)) {
            throw new Exception("La somma " + totale + " non e' valida");
        }
        this.credito += totale*2;
    }


    @Override
    public String toString() {
       return String.format("( UtenteBus: %s %s : [%s] : Credito %.2f : Data di Nascita %s )", 
                    this.getCognome(), this.getNome(), this.getCodiceFiscale(), 
                    this.getCredito(), this.getSimpleDataNascita());
    }    


    @Override
    public void addAbbonamento(Abbonamento a) throws Exception {
        // se il costo dell'abbonamento è minore o uguale
        // del credito residuo posso sottoscriverlo
        // altrimenti restituisco un errore
        
        if (a.getCosto() <= this.getCredito()) {
            this.getAbbonamenti().add(a);
            // decremento il valore del credito
            this.credito -= a.getCosto();
        }
        else {
            throw new Exception("Costo dell'abbonamento " + a.getCosto() + " maggiore del credito " + this.getCredito());
        }
    }

}
