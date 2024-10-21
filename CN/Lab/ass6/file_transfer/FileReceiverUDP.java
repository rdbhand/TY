import java.io.*;
import java.net.*;

public class FileReceiverUDP {
    public static void main(String[] args) throws IOException {
        DatagramSocket ds = new DatagramSocket(5000);
        byte[] buf = new byte[4096];
        FileOutputStream fos = new FileOutputStream("recv_file.txt");

        DatagramPacket dp;
        int len;
        while (true) {
            dp = new DatagramPacket(buf, buf.length);
            ds.receive(dp);
            len = dp.getLength();
            if (len == -1) break;
            fos.write(buf, 0, len);
        }

        fos.close();
        ds.close();
    }
}
