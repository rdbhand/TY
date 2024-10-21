import java.io.*;
import java.net.*;

public class CalcClient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 5001);
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);
            String expr = "10 + 5";
            out.println(expr);
            String res = in.readLine();
            System.out.println(res);
            in.close();
            out.close();
            s.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
