/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package esempi;

/**
 *
 * @author giulio
 */
public class Pet {
    
    // il modificatore "static" indica che petsNumber 
    // è un attributo di classe e non di oggetto
    private static int petsNumber = 0;  
    
    private String petName = "dummy";
    private final String chipCode;  // le final non devono essere valorizzate nella definizione

    /**
     * Costruttore: prende nome dell'animale e valore del chip
     * @param petName
     * @param chipCode 
     */
    public Pet (String petName, String chipCode) {
        this.petName = petName;
        // unico posto in cui posso valorizzare un attributo final
        this.chipCode = chipCode;
        Pet.petsNumber++;
    }
    
    /**
     * Valorizza l'attributo petName
     * @param n 
     */
    public void setPetName(String petName) {
        this.petName = petName;
    }
    
    /**
     * Restituisce il valore dell'attributo petname
     * @return string petname 
     */
    public String getPetName() {
        return this.petName;
    }

    /**
     * Ridefinisco la rappresentazione Stringa della classe
     * @return 
     */
    public String toString() {
        return "(Animaletto: " + this.petName + ", Code: " + this.chipCode + ")";
    }
    
    /**
     * Valorizza l'attributo chipCode
     * @param n 
     */
    public String getChipCode() {
        return this.chipCode;
    }

//    public void setChipCode(String cc) {
//        this.chipcode = chipcode;   // NON SI PUO' FARE PERCHE' L'ATTRIBUTO E' final
//    }
    
    /// METODI STATICI (metodi di classe)
       
    /**
     * Numero di animali inseriti
     * @return int numero di animali presenti
     */
    public static int quanti() {
        return Pet.petsNumber;
    }
        
}
