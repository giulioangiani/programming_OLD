package pkg03_socket_thread;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class ClientHandler extends Thread {

    DateFormat fordate = new SimpleDateFormat("yyyy/MM/dd");
    DateFormat fortime = new SimpleDateFormat("hh:mm:ss");
    final BufferedReader dis;
    final PrintWriter dos;
    final Socket s;

    // Constructor 
    public ClientHandler(Socket s, BufferedReader dis, PrintWriter dos) {
        this.s = s;
        this.dis = dis;
        this.dos = dos;

    }

    @Override
    public void run() {
        String received;
        String toreturn;
        while (true) {
            try {
                System.out.println("SONO NEL THREAD");
                String in_msg = dis.readLine();
                System.out.println("ricevuto da client: " + in_msg);

                if (in_msg.equals(".q")) {
                    System.out.println("Connessione chiusa dal client");
                    this.s.close();
                    break;
                }

                // inserisco un ritardo di 5 secondi per simulare
                // una elaborazione pesante sul server...
                
                Thread.sleep(5000);
                
                String out_msg = "sono il server: ho ricevuto  " + in_msg;

                // Ask user what he wants 
                dos.println(out_msg);

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        try {
            // closing resources 
            this.dis.close();
            this.dos.close();
            this.s.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
