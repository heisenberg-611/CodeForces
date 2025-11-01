import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class G_Mukhammadali_and_the_Smooth_Array{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            
            long[] a = new long[n];
            long[] c = new long[n];
            long totalCost = 0;
            
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st1.nextToken());
            }
            for (int i = 0; i < n; i++) {
                c[i] = Long.parseLong(st2.nextToken());
                totalCost += c[i];
            }

            // dp[i] = max sum of costs ending at i (keeping i unchanged)
            long[] dp = new long[n];
            long maxUnchanged = 0;

            for (int i = 0; i < n; i++) {
                dp[i] = c[i]; // at least keep just i
                for (int j = 0; j < i; j++) {
                    if (a[j] <= a[i]) {
                        if (dp[j] + c[i] > dp[i]) {
                            dp[i] = dp[j] + c[i];
                        }
                    }
                }
                if (dp[i] > maxUnchanged) {
                    maxUnchanged = dp[i];
                }
            }

            long ans = totalCost - maxUnchanged;
            sb.append(ans).append('\n');
        }

        System.out.print(sb);
    }
}
