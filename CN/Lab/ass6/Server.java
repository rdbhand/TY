import java.io.*;
import java.net.*;
public class Server {
    public static void main(String args[]) throws IOException {
        DatagramSocket s = new DatagramSocket(9090);
        byte[] rBuf = new byte[1024];
        byte[] sBuf;

        System.out.println("Server is running and waiting for client message ...");

        DatagramPacket rPkt = new DatagramPacket(rBuf, rBuf.length);
        s.receive(rPkt);
        String cMsg = new String(rPkt.getData(), 0, rPkt.getLength());
        System.out.println("Client says: " + cMsg);


        String reply = "Message received by the server.";
        sBuf = reply.getBytes();
        InetAddress cAddr = rPkt.getAddress();
        int cPort = rPkt.getPort();
        DatagramPacket sPkt = new DatagramPacket(sBuf, sBuf.length, cAddr, cPort);
        s.send(sPkt);

        s.close();
    }
}