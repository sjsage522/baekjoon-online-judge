import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
  static void calAvg(int[] arr) {
    int len = arr.length, sum = 0;
    for(int i=0; i<len; i++)
      sum += arr[i];
    System.out.println(sum / len);
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] arr = new int[5];
    int temp;

    for(int i=0; i<arr.length; i++) {
      temp = Integer.parseInt(br.readLine());
      if(temp < 40) {
        arr[i] = 40;
      }
      else {
        arr[i] = temp;
      }
    }

    calAvg(arr);
  }
}