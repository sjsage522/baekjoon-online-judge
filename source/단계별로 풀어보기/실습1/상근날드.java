import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int min1 = 2001, min2 = 2001;
    int[] arr = new int[5];
    Arrays.fill(arr, 0);
    
    for(int i=0; i<3; i++) {
      arr[i] = Integer.parseInt(br.readLine());
      if(min1 > arr[i])
        min1 = arr[i];
    } 
    for(int i=3; i<5; i++) {
      arr[i] = Integer.parseInt(br.readLine());
      if(min2 > arr[i])
        min2 = arr[i];
    }

    System.out.println(min1 + min2 - 50);
  }
}