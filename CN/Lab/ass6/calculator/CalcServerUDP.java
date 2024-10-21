import java.net.*;

public class CalcServerUDP {
    public static void main(String[] args) throws Exception {
        DatagramSocket ds = new DatagramSocket(5001);
        byte[] buf = new byte[256];
        DatagramPacket dp = new DatagramPacket(buf, buf.length);
        ds.receive(dp);
        String expr = new String(dp.getData(), 0, dp.getLength());

        String[] p = expr.split(" ");
        int a = Integer.parseInt(p[0]), b = Integer.parseInt(p[2]);
        int res = 0;
        switch (p[1].charAt(0)) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
        }

        String result = "Result: " + res;
        buf = result.getBytes();
        dp = new DatagramPacket(buf, buf.length, dp.getAddress(), dp.getPort());
        ds.send(dp);
        ds.close();
    }
}
