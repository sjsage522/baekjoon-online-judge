import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int n = Integer.parseInt(br.readLine());

    int temp, count = 0;

    if(n < 100) {
      System.out.println(n);
    }
    else if(n < 1000){
      int a, b, c;
      for(int i=100; i<=n; i++) {
        temp = i;
        a = temp % 10;
        temp /= 10;
        b = temp % 10;
        temp /= 10;
        c = temp % 10;
        if(a-b == b-c) {
          count++;
        }
      }
      System.out.println(count + 99);
    }

    else
      System.out.println(144);
  }
}