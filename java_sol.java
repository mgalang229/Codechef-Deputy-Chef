import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int tt = in.nextInt();
    for (int qq = 1; qq <= tt; qq++) {
      int n = in.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      int[] d = new int[n];
      for (int i = 0; i < n; i++) {
        d[i] = in.nextInt();
      }
      int best_defense = -1;
      for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
          if (a[n - 1] + a[i + 1] < d[i]) {
            best_defense = Math.max(best_defense, d[i]);
          }
        } else {
          if (a[i - 1] + a[i + 1] < d[i]) {
            best_defense = Math.max(best_defense, d[i]);
          }
        }
      }
      if (a[n - 2] + a[0] < d[n - 1]) {
        best_defense = Math.max(best_defense, d[n - 1]);
      }
      System.out.println(best_defense);
    }
  }
}
