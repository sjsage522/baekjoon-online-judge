import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());

    BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    for(int i=1; i<=n*2; i++) {
      for(int j=1; j<=n; j++) {
        if(i % 2 == 0) {
          if(j % 2 == 0) {
            out.write("*");
            out.flush();
          } else {
            out.write(" ");
            out.flush();
          }
        }
        else {
          if(j % 2 == 0) {
            out.write(" ");
            out.flush();
          } else {
            out.write("*");
            out.flush();
          }
        }
      }
      out.newLine();
    }
    out.close();
  }
}