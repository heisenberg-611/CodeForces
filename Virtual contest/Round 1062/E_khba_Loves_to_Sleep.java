import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class E_khba_Loves_to_Sleep {
    static class Interval {
        long l, r;

        Interval(long l, long r) {
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            long x = Long.parseLong(st.nextToken());
            st = new StringTokenizer(br.readLine());
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
            }
            Arrays.sort(a);

            // Binary search on D
            long low = 0, high = x;
            long bestD = 0;
            while (low <= high) {
                long mid = (low + high) / 2;
                if (canPlace(a, x, k, mid)) {
                    bestD = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Generate forbidden intervals with bestD
            List<Interval> forbidden = new ArrayList<>();
            for (long pos : a) {
                long L = Math.max(0, pos - bestD + 1);
                long R = Math.min(x, pos + bestD - 1);
                if (L <= R) {
                    forbidden.add(new Interval(L, R));
                }
            }

            // Merge forbidden intervals
            List<Interval> merged = new ArrayList<>();
            for (Interval interval : forbidden) {
                if (merged.isEmpty()) {
                    merged.add(interval);
                } else {
                    Interval last = merged.get(merged.size() - 1);
                    if (interval.l <= last.r + 1) {
                        last.r = Math.max(last.r, interval.r);
                    } else {
                        merged.add(interval);
                    }
                }
            }

            // Get safe intervals
            List<Interval> safe = new ArrayList<>();
            long current = 0;
            for (Interval interval : merged) {
                if (current <= interval.l - 1) {
                    safe.add(new Interval(current, interval.l - 1));
                }
                current = interval.r + 1;
            }
            if (current <= x) {
                safe.add(new Interval(current, x));
            }

            // Output k positions
            int count = 0;
            for (Interval interval : safe) {
                for (long pos = interval.l; pos <= interval.r && count < k; pos++) {
                    sb.append(pos).append(' ');
                    count++;
                }
                if (count >= k)
                    break;
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }

    static boolean canPlace(long[] a, long x, int k, long D) {
        // Create forbidden intervals: positions where |pos - friend| < D
        List<Interval> forbidden = new ArrayList<>();
        for (long pos : a) {
            long L = Math.max(0, pos - D + 1);
            long R = Math.min(x, pos + D - 1);
            if (L <= R) {
                forbidden.add(new Interval(L, R));
            }
        }

        // Merge intervals
        List<Interval> merged = new ArrayList<>();
        for (Interval interval : forbidden) {
            if (merged.isEmpty()) {
                merged.add(interval);
            } else {
                Interval last = merged.get(merged.size() - 1);
                if (interval.l <= last.r + 1) {
                    last.r = Math.max(last.r, interval.r);
                } else {
                    merged.add(interval);
                }
            }
        }

        // Calculate total safe integer points
        long total = 0;
        long current = 0;
        for (Interval interval : merged) {
            if (current <= interval.l - 1) {
                total += (interval.l - current);
            }
            current = interval.r + 1;
            if (total >= k)
                return true;
        }
        if (current <= x) {
            total += (x - current + 1);
        }
        return total >= k;
    }
}