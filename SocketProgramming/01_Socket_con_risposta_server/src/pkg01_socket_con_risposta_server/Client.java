package pkg01_socket_con_risposta_server;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class Client {


    private static int port = 12345;
    private static String serveraddress = "localhost";

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws UnknownHostException, IOException {
        String messaggio = "";
        java.util.Scanner sc = new Scanner(System.in);
        
        // preparazione dell'indirizzo del server
        InetAddress address = InetAddress.getByName("localhost");

        // creazione socket
        Socket client = new Socket(serveraddress, port);

        // creazione buffer di scrittura
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);
        
        System.out.println("Client ready.\n");
        System.out.println("Inserisci un messaggio e premi INVIO [.quit per uscire]");
        while (true) {
            
            messaggio = sc.nextLine();
            if (messaggio.equals(".quit")) {
                System.out.println("Sending quit message...");
                out.println(messaggio);
                break;
            }
        
            System.out.println("Buffer ready, sending message \"" + messaggio + "\"...\n");

            // scrittura del messaggio (passato come parametro) nel buffer in uscita
            out.println(messaggio);
            System.out.println("Message sent.\n");

            // in attesa di risposta del server
            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            String server_response = in.readLine();

            System.out.println("Il server mi ha risposto: " + server_response);
            
        }

        // chiusura socket
        client.close();
    }

}
