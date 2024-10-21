import java.io.*;
import java.net.*;

public class FRecv {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(5000);
            Socket s = ss.accept();
            DataInputStream dis = new DataInputStream(s.getInputStream());
            FileOutputStream fos = new FileOutputStream("recv.txt");
            byte[] buf = new byte[4096];
            int bytesRead;
            while ((bytesRead = dis.read(buf)) != -1) {
                fos.write(buf, 0, bytesRead);
            }
            fos.close();
            dis.close();
            s.close();
            ss.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
