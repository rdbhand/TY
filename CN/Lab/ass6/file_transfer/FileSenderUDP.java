import java.io.*;
import java.net.*;

public class FileSenderUDP {
    public static void main(String[] args) throws IOException {
        DatagramSocket ds = new DatagramSocket();
        InetAddress ip = InetAddress.getByName("localhost");
        FileInputStream fis = new FileInputStream("send_file.txt");
        byte[] buf = new byte[4096];

        int len;
        while ((len = fis.read(buf)) != -1) {
            DatagramPacket dp = new DatagramPacket(buf, len, ip, 5000);
            ds.send(dp);
        }

        fis.close();
        ds.close();
    }
}
