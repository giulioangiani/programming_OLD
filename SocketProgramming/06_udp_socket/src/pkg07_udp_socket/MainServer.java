package pkg07_udp_socket;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

/**
 *
 * @author Giulio Angiani (IIS Pascal - Reggio Emilia)
 */
public class MainServer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws SocketException, IOException {
        // TODO code application logic here
        DatagramSocket serverSocket = new DatagramSocket(9876);
        System.out.println("Server pronto: ");
        byte[] receiveData = new byte[1024]; 
        while (true) {
            DatagramPacket receivePacket= new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            String messaggio = new String(receivePacket.getData()).trim(); 
            System.out.println("Ricevuto: " + messaggio + " length:" + receiveData.length + " [" + messaggio.length() + "]");
        }

    }

}