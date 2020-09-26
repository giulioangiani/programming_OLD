package pkg04_chat_testuale;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;


/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class Main {

    public static final String ANSI_RED = "\u001B[35m";
    public static final String ANSI_GREEN = "\u001B[32m";
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, InterruptedException {

        int localport = Integer.parseInt(args[0]);
        // l'indirizzo e la porta del peer al quale scrivere
        // sono passati da riga di comando
        String remoteaddress = args[1];
        int remoteport = Integer.parseInt(args[2]);

        Thread serverthread = new ServerThread(localport);
        serverthread.start();

        // running infinite loop for sending data 
        // creazione send socket
        Scanner sc = new Scanner(System.in);
        System.out.println("Client pronto [.q per uscire]");

        while (true) {
            try {
                System.out.print(Main.ANSI_GREEN + ">> ");
                String msg_to_send = sc.nextLine();
                if (msg_to_send.equals (".q")) System.exit(0);


                Socket client =  new Socket(remoteaddress, remoteport);
                PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);
                BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                out.println(msg_to_send);
                in.readLine();
                client.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    // TODO code application logic here
}

