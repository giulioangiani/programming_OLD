package udpsocketClientSender;

import java.io.*;
import java.net.*;
import java.util.Scanner;


public class UDPClientSender{
              

   public static void main(String[] args) throws IOException  {
      // Configurazione Porta del server:
      //if(args.length < 2) throw new IOException("Uso: UDPClientSender <Server> <port>");
      int serverPort = 6789;
      InetAddress serverAddress=  InetAddress.getByName("localhost");// serverAdress è una variabile di tipo InetAddress che conterrà l'indirizzo del server UDP
            
      if(args.length == 2)  //se specificati da terminale sovrascrivono i valori preimpostati del IP e PORTA del server
        {
            serverPort= Integer.parseInt(args[0]);
            serverAddress = InetAddress.getByName( args[1]);
        }
      
  

      // Richiesta a video del contenuto del pacchetto da spedire
      System.out.println("Scrivi il messaggio da spedire");
      Scanner tastiera =new Scanner(System.in);
      String message = tastiera.nextLine();
      

      try{
         
       // Istanziamo il Socket UDP
	   DatagramSocket dSocket = new DatagramSocket();

       // prepariamo il Pacchetto UDP con la richiesta da inviare
	   DatagramPacket  outPacket = new DatagramPacket(message.getBytes(),
                                                         message.length(),
                                                         serverAddress, serverPort);
					
					
	   // Invia il pacchetto
	   dSocket.send(outPacket);
        
         
           System.out.println("comunicazione chiusa");
	   dSocket.close();
      }
      catch(IOException e)
      {
	 System.err.println(e.getMessage());
      }
   } //end main
} //end class
