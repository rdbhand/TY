import java.io.*;
import java.net.*;

public class FSend {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 5000);
            FileInputStream fis = new FileInputStream("send.txt");
            DataOutputStream dos = new DataOutputStream(s.getOutputStream());
            byte[] buf = new byte[4096];
            int bytesRead;
            while ((bytesRead = fis.read(buf)) != -1) {
                dos.write(buf, 0, bytesRead);
            }
            fis.close();
            dos.close();
            s.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
