import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static char[][] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new char[n][n];
        
        init();
        solution(n, 0, 0);
        print();
    }

    static void init() {
        for (char[] chars : arr)
            Arrays.fill(chars, ' ');
    }
    static void solution(int n, int x, int y) {
        if(n == 1) {
            arr[x][y] = '*';
            return;
        }
        int div = n/3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==1 && j==1) {
                    continue;
                }
                solution(div, x+(div*i), y+(div*j));
            }
        }
    }
    static void print() {
        for (char[] chars : arr)
            System.out.println(chars);
    }
}