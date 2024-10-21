import java.io.*;
import java.net.*;

public class Client {
    public static void main(String args[]) throws IOException {
        DatagramSocket cSock = new DatagramSocket();
        InetAddress sAddr = InetAddress.getByName("localhost");

        String msg = "Hello from client!";
        byte[] sBuf = msg.getBytes();
        DatagramPacket sPkt = new DatagramPacket(sBuf, sBuf.length, sAddr, 9090);
        cSock.send(sPkt);

        byte[] rBuf = new byte[1024];
        DatagramPacket rPkt = new DatagramPacket(rBuf, rBuf.length);
        cSock.receive(rPkt);
        String sMsg = new String(rPkt.getData(), 0, rPkt.getLength());
        System.out.println("Server says: " + sMsg);

        cSock.close();
    }
}