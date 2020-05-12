import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] res = new String[10001];
        int n = sc.nextInt();
        int j = 0, start = 666;
        do {
            String s = Integer.toString(start);
            int cnt = 0;
            for (int i = 0; i < s.length() - 2; i++) {
                if ((s.charAt(i)) == '6' && s.charAt(i + 1) == '6'
                   &&s.charAt(i+2) == '6') {
                    cnt++;
                }
            }
            if (cnt >= 1) {
                res[++j] = s;
            }
            start++;
        } while (j != n);
        System.out.println(res[n]);
    }
}