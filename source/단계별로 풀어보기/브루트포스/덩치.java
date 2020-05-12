import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[][] tp = new String[n][2];
        int[][] p = new int[n][2];
        int[] rank = new int[n];

        for(int i=0; i<n; i++) {
           tp[i] = br.readLine().split(" ");
           p[i][0] = Integer.parseInt(tp[i][0]);
           p[i][1] = Integer.parseInt(tp[i][1]);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) {
                    continue;
                }
                else if(p[i][0] < p[j][0] && p[i][1] < p[j][1]) {
                    rank[i]++;
                }
            }
        }
        for(int i=0; i<n; i++) {
            bw.write(rank[i]+1 + " ");
        }
        bw.flush();
        bw.close();
    }
}