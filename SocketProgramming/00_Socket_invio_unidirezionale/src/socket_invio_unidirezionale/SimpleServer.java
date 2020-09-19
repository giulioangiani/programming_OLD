package socket_invio_unidirezionale;

import java.net.*;
import java.io.*;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */

public class SimpleServer
{
	public static void main(String[] args)
	{
		try
		{
			// apertura del socket server
			ServerSocket server = new ServerSocket(12345);
			
			// dichiarazione del socket client e del buffer di ingresso
			Socket client;
			BufferedReader in;
			
			System.out.println("Server ready (CTRL-C quits)\n");
			
			// ciclo infinito
			while(true)
			{
				// chiamata bloccante, in attesa di connessione da parte di un client
				client = server.accept();
				System.out.println("Client connected: "+client);
				
				// lettura e stampa del messaggio in ingresso
				in = new BufferedReader(new InputStreamReader(client.getInputStream()));
				System.out.println(">> "+client.getInetAddress()+": "+in.readLine()+"\n");
				
				// chiusura del client socket
				client.close();
			}
			
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
