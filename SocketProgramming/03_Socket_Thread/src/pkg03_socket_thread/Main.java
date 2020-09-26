package pkg03_socket_thread;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // server is listening on port 5056 
        ServerSocket ss = new ServerSocket(5056);

        // running infinite loop for getting 
        // client request 
        while (true) {
            

            try {
                System.out.println("Server pronto [Ctrl+C per uscire]");
                // socket object to receive incoming client requests 
                Socket client = null;
                client = ss.accept();

                System.out.println("A new client is connected : " + client);

                BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);
                
                
                System.out.println("Assigning new thread for this client");

                // create a new thread object 
                Thread t = new ClientHandler(client, in, out);
                // Invoking the start() method 
                t.start();
                
                

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    // TODO code application logic here
}

