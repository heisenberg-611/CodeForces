import java.io.*;
import java.util.*;

public class C_Isamatdin_and_His_Magic_Wand {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (q-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int[] a = new int[n];
            boolean hasEven = false, hasOdd = false;
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
                if (a[i] % 2 == 0)
                    hasEven = true;
                else
                    hasOdd = true;
            }

            if (hasEven && hasOdd) {
                Arrays.sort(a);
            }

            for (int i = 0; i < n; i++) {
                sb.append(a[i]).append(' ');
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }
}