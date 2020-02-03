package compagniatelefonica;

import java.util.ArrayList;
import java.util.List;

public class SIM {
    private String numero;

    /**
     * <Enter note text here>
     */
    private float creditoResiduo = 0;

    public List<Telefonata> telefonata = new ArrayList<Telefonata> ();

    /**
     * Costruttore: prende in input numero di telefono della SIM
     */
    public SIM(String numero, float credito) {
        this.numero = numero;
        this.creditoResiduo = credito;
    }

    public String getNumero() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.numero;
    }

    public void setNumero(String numero) {
        // Automatically generated method. Please delete this comment before entering specific code.
        this.numero = numero;
    }

    public float getCreditoResiduo() {
        // Automatically generated method. Please delete this comment before entering specific code.
        return this.creditoResiduo;
    }

    public void addTelefonata(Telefonata p1) {
    }

    /**
     * <Enter note text here>
     */
    public void ricaricaCredito(float ricarica) {
    }
    
    
    public int getMinutiTotaliConversazione() {
        return 0;
    }

    public ArrayList<Telefonata> getListaTelefonatePerNumero(String numero) {
        return null;
    }
}
