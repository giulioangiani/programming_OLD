/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package busflix;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.GregorianCalendar;

/**
 *
 * @author giulio
 */
public class Utente {
    private final String nome;
    private final String cognome;
    private final String codiceFiscale;
    protected float credito = 0;
    private GregorianCalendar dataNascita = null;
    
    // per inizializzare un arraylist statico
    public static final ArrayList<Integer> RICARICHE_VALIDE = new ArrayList<>(
        Arrays.asList(5, 10, 20, 50)
    );
    
    
    // gestione abbonamento
    private ArrayList<Abbonamento> abbonamenti = new ArrayList<>();
    
    public Utente(String nome, String cognome, String codiceFiscale) {
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
        this.dataNascita = new GregorianCalendar(1970, 0, 1);
    }
    
    public Utente(String nome, String cognome, String codiceFiscale, GregorianCalendar dn) {
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
        this.dataNascita = dn;
    }
        
    public String getNome() {
        return this.nome;
    }
    public String getCognome() {
        return this.cognome;
    }
    public String getCodiceFiscale() {
        return this.codiceFiscale;
    }

    public GregorianCalendar getDataNascita() {
        return this.dataNascita;
    }

    public String getSimpleDataNascita() {
        SimpleDateFormat fmt = new SimpleDateFormat("dd-MMM-yyyy");
        String dateFormatted = fmt.format(this.dataNascita.getTime());
        return dateFormatted;
    }
    
    public float getCredito() {
        return this.credito;
    }

    // metodi di modifica
    public void setDataNascita(GregorianCalendar dn) {
        this.dataNascita = dn;
    }
    
    public void ricarica(int totale) throws java.lang.Exception {
        if (!Utente.RICARICHE_VALIDE.contains(totale)) {
            throw new Exception("La somma " + totale + " non e' valida");
        }
        this.credito += totale;
    }
    
    
    @Override
    public String toString() {
       return String.format("( Utente: %s %s : [%s] : Credito %.2f : Data di Nascita %s )", this.cognome, this.nome, this.codiceFiscale, this.getCredito(), this.getSimpleDataNascita());
    }

    
    // gestione abbonamenti
    // nella classe Utente creiamo un ArrayList di Abbonamento
    // per realizzare la relazione 0-N presente nell'UML
    public void addAbbonamento(Abbonamento a) throws Exception {
        // se il costo dell'abbonamento è minore o uguale
        // del credito residuo posso sottoscriverlo
        // altrimenti restituisco un errore
        
    //    System.out.println("Abbonamento da sottoscrivere =  " + a);
        
    //    if (a instanceof AbbonamentoSpeciale) {
    //        throw new Exception("Errore 1 - prima soluzione - Questo utente non puo' sottoscrivere questo tipo di abbonamento ");
    //    }
        
        // test tipo abbonamento
        if (!a.getClass().getSimpleName().equals("Abbonamento")) {
            throw new Exception("Questo utente non puo' sottoscrivere questo tipo di abbonamento ");
        }
        
        
        if (a.getCosto() <= this.getCredito()) {
            this.abbonamenti.add(a);
            // decremento il valore del credito
            this.credito -= a.getCosto();
        }
        else {
            throw new Exception("Costo dell'abbonamento " + a.getCosto() + " maggiore del credito " + this.getCredito());
        }
    }
    
    public ArrayList<Abbonamento> getAbbonamenti() {
        return this.abbonamenti;
    }
    
}
