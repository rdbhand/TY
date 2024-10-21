import java.io.*;
import java.net.*;

public class CalcServer {
    public static void main(String[] args) {
        try {
            ServerSocket ss = new ServerSocket(5001);
            Socket s = ss.accept();
            BufferedReader in = new BufferedReader(new InputStreamReader(s.getInputStream()));
            PrintWriter out = new PrintWriter(s.getOutputStream(), true);
            String expr = in.readLine();
            String[] p = expr.split(" ");
            int n1 = Integer.parseInt(p[0]);
            String op = p[1];
            int n2 = Integer.parseInt(p[2]);
            int res = 0;
            switch (op) {
                case "+": res = n1 + n2; break;
                case "-": res = n1 - n2; break;
                case "*": res = n1 * n2; break;
                case "/": res = n1 / n2; break;
            }
            out.println("Result: " + res);
            in.close();
            out.close();
            s.close();
            ss.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
