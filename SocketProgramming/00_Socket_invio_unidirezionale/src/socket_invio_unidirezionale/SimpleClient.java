package socket_invio_unidirezionale;

import java.net.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class SimpleClient {
	public static void main(String[] args) throws UnknownHostException, IOException
	{
                String messaggio = "";
                // verifica correttezza dei parametri
                if (args.length > 0)
                {
                    messaggio = args[0];
                }
                else {
                    messaggio = "Ciao Server!";
                }
                
                // preparazione dell'indirizzo del server
                InetAddress address = InetAddress.getByName("localhost");

                // creazione socket
                Socket client = new Socket(address, 12345);

                System.out.println("Client ready.\n");

                // creazione buffer di scrittura
                PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);

                System.out.println("Buffer ready, sending message \""+ messaggio +"\"...\n");

                // scrittura del messaggio (passato come parametro) nel buffer in uscita
                out.println(messaggio);

                System.out.println("Message sent.\n");

                // chiusura socket
                client.close();
	}
}
