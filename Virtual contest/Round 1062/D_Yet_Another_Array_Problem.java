import java.io.*;
import java.util.StringTokenizer;

public class D_Yet_Another_Array_Problem{
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
            }

            long ans = -1;
            for (long x = 2; x <= 60; x++) {
                boolean found = false;
                for (int i = 0; i < n; i++) {
                    if (gcd(a[i], x) == 1) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    ans = x;
                    break;
                }
            }

            sb.append(ans).append('\n');
        }

        System.out.print(sb);
    }
}