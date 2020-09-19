package pkg01_socket_con_risposta_server;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class Server {

    private static int port = 12345;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            // apertura del socket server
            ServerSocket server = new ServerSocket(port);

            // dichiarazione del socket client e del buffer di ingresso e di uscita

            System.out.println("Server ready (CTRL-C quits)\n");
            Socket client;
            // chiamata bloccante, in attesa di connessione da parte di un client
            client = server.accept();
            System.out.println("Client connected: " + client);
            // ciclo infinito
            // lettura e stampa del messaggio in ingresso
            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);

            while (true) {

                String received_message = in.readLine();
                if (received_message.equals(".quit")) {
                    System.out.println("Received quit message...");
                    break;
                }

                Object client_ip_address = client.getInetAddress();
                System.out.println(">> " + client_ip_address + ": " + received_message + "\n");

                out.println("Wow! I've received your message : " + received_message);
                out.flush();
                // chiusura del client socket
            }
            out.close();
            in.close();
            client.close();
            server.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
