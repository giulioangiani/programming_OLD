/* Applicazione Client Server sotto protocollo UDP, che consentire aserver 
 * di visualizzare a video tutti i dati e msggi ricevuti dai clients (client elaborati senza thread)
 */
package udpsocketServerReceiver;



import java.io.*;
import java.net.*;

public class UDPServerReceiver {

    

    
    
public static void main(String args[]) throws IOException {
     
    // Impostazione Porta del server:
    // if(args.length != 1) throw new IOException("Uso: UDPServerReceiver <port>");
    int port= 6789;
    if(args.length == 1) port=Integer.parseInt(args[0]); //se specificata come argomento, la porta diventa quella specificata, altrimenti =2000
            

    try
    {
        // Server apre Socket UDP alla porta port
        DatagramSocket dsocket = new DatagramSocket(port);
        DatagramPacket inPacket;  //inPacket conterrà il pkt ricevuto dal client
        System.out.println("Server in attesa di messaggi sulla porta " + port + "\n");
        
        // Buffer per il contenuto del pacchetto da ricevere
        byte buffer[] = new byte[512];

        while (true){
               


               // inPacket è il Pacchetto UDP ricevuto dal client
               inPacket = new DatagramPacket(buffer, buffer.length);

               //riceve ed elabora pacchetto dal client
               dsocket.receive(inPacket);
               System.out.print("Ricevuto messaggio da  ");
               showPacket(inPacket);


                       /* Recupera, dall'oggetto DatagramPacket ricevuto,
                              sia l'indirizzo IP che la porta UDP del client */
               InetAddress clientAddress = inPacket.getAddress();
               int clientPort            = inPacket.getPort();




       }  //end while
     }
     catch(IOException e)
     {
        System.err.println("riscontrato errore: " + e);}
     }  //end main



static protected void showPacket(DatagramPacket pktClient) throws IOException {
    //recupera IP e Porta del Client e dati del msg dal pacchetto arrivato
    System.out.print  ("Mittente : " + pktClient.getAddress());
    System.out.print  ("  porta : "    + pktClient.getPort()) ;
    System.out.println("  Lunghezza messaggio : " + pktClient.getLength());

    
    // pktClient.getData() restituisce l'array di byte del datagramma ricevuto dal client
    // messagIn = tutti i byte del datagramma ricevuto convertiti in stringa  
    String messageIn = new String(pktClient.getData(),0,pktClient.getLength());
    

    System.out.println("Messaggio : " + messageIn);
}
}