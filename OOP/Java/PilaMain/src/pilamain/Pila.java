

package pilamain;


public class Pila {
    //dichiaro un array di 10 elementi
    private int vet[];
    private int c=0;
    private int dim;
    
    // Il costruttore prevede l'inserimento del parametro dimensione della pila
    public Pila(int dim){
        this.dim = dim;
        vet=new int [dim];
    }
    
    // Se la dimensione non viene specifcata si assegna 10 di default
    public Pila(){
        dim = 10;
        vet=new int[dim];
    }
    
    //metodo push (se supera il limite massimo restituisce false)
    public boolean push(int elem){
        if(c<dim){
            vet[c]=elem;
            c++;
        }
        else {
            return false;
        }
        return true;   
    }
    
    //metodo pop- se la pila è vuota parte un'eccezione
    public int pop() throws Exception {
         if(c<=0) {
             throw new Exception("non ci sono elementi");
         }
         else{
            c--;
            int appoggio = vet[c];
            return appoggio;
         }
         
    }
    
    
}