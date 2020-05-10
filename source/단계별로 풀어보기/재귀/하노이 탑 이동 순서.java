import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        bw.write((int)Math.pow(2,n)-1 + "\n");
        hanoiTower(n, 1, 2, 3);
        bw.flush();
        bw.close();
    }

    static void hanoiTower(int n, int s, int t, int e) throws IOException {
        if(n == 1) {
            bw.write(s + " " + e + "\n");
            return;
        }
        hanoiTower(n-1 ,s, e, t);
        bw.write(s + " " + e + "\n");
        hanoiTower(n-1, t, s, e);
    }
}