import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        String[] chess1 = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};
        String[] chess2 = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        String[] in = new String[n];
        for(int i=0; i<n; i++) {
            in[i] = br.readLine();
        }
        int res = Integer.MAX_VALUE;
        res = getRes(n, m, in, res, chess1);
        res = getRes(n, m, in, res, chess2);
        bw.write(res + "\n");
        bw.flush();
        bw.close();
        br.close();
    }

    static int getRes(int n, int m, String[] in, int res, String[] chess) {
        for(int i=0; i<=n-8; i++) {
            for(int j=0; j<= m-8; j++) {
                int cnt = 0;
                for(int k=0; k<8; k++) {
                    for(int l=0; l<8; l++) {
                        if (in[k+i].charAt(l+j) != chess[k].charAt(l)) {
                            cnt++;
                        }
                    }
                }
                res = Math.min(res, cnt);
            }
        }
        return res;
    }
}