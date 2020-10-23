package pkg07_udp_socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class MainClient {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws SocketException, UnknownHostException, IOException {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("Inserisci il messaggio [.q per uscire]: ");
            String line = sc.nextLine();
            if (line.equals(".q")) break;
            DatagramSocket clientSocket = new DatagramSocket();
            byte[] sendData = line.getBytes(); 
            InetAddress IPAddress = InetAddress.getLoopbackAddress();
            System.out.println("IPAddress = " + IPAddress);
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
            clientSocket.send(sendPacket); 
            System.out.println("Dati inviati");
            clientSocket.close();
        }
    }
    
}
