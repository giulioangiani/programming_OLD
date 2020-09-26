package pkg04_chat_testuale;


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class ServerThread extends Thread {

    DateFormat fordate = new SimpleDateFormat("yyyy/MM/dd");
    DateFormat fortime = new SimpleDateFormat("hh:mm:ss");

    final ServerSocket ss;
    private PrintStream ps;

    // Constructor 
    public ServerThread(int localport) throws IOException {
        // server is listening on port specified by user 
        this.ss = new ServerSocket(localport);
        this.ps = ps;
    }

    @Override
    public void run() {
        String received;
        String toreturn;
        System.out.println("Server pronto [Ctrl+C per uscire]");
        while (true) {
            try {

                Socket client = null;
                client = ss.accept();

                BufferedReader dis = new BufferedReader(new InputStreamReader(client.getInputStream()));
                PrintWriter dos = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);

                String in_msg = dis.readLine();
                System.out.print(Main.ANSI_RED + "\b\b\b\b<< " + in_msg + Main.ANSI_GREEN  + "\n>> ");
                String out_msg = "[OK]";
                dos.println(out_msg);
 
                client.close();

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
