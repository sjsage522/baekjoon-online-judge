import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int result = solution(n);

        if(result == n)
            System.out.println(0);
        else
            System.out.println(result);
    }

    static int solution(int n) {
        int res, sum, start = 1;
        while(true) {
            sum = 0;
            String val = String.valueOf(start);
            for (int i = 0; i < val.length(); i++) {
                sum += Integer.parseInt(val.substring(i, i + 1));
            }

            res = start + sum;
            if (res == n || start == n) {
                break;
            }
            start++;
        }
        return start;
    }
}
