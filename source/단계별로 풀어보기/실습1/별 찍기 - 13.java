import java.util.Scanner;

class Main {
  public static void main(String[] args) {

    int n;

    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();

    for(int i=0; i<(2*n)-1; i++) {
      if(i <= ((2*n)-1) / 2)
        for(int j=0; j<i+1; j++)
          System.out.print("*");
      else
        for(int j=i; j<(2*n)-1; j++)
          System.out.print("*");
      
      System.out.println();
    }
  }
}