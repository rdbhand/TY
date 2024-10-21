import java.net.*;

public class CalcClientUDP {
    public static void main(String[] args) throws Exception {
        DatagramSocket ds = new DatagramSocket();
        InetAddress ip = InetAddress.getByName("localhost");
        String expr = "10 + 5";
        byte[] buf = expr.getBytes();
        DatagramPacket dp = new DatagramPacket(buf, buf.length, ip, 5001);
        ds.send(dp);

        buf = new byte[256];
        dp = new DatagramPacket(buf, buf.length);
        ds.receive(dp);
        String res = new String(dp.getData(), 0, dp.getLength());
        System.out.println(res);

        ds.close();
    }
}
