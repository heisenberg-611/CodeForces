import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A_Round_Trip {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long R0 = Long.parseLong(st.nextToken());
            long X = Long.parseLong(st.nextToken());
            long D = Long.parseLong(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            
            String rounds = br.readLine().trim();
            
            long rating = R0;
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                char c = rounds.charAt(i);
                if (c == '1') {
                    // Div. 1 round: always rated
                    count++;
                    rating = Math.max(0, rating - D);
                } else {
                    // Div. 2 round: rated only if rating < X
                    if (rating < X) {
                        count++;
                        rating = Math.max(0, rating - D);
                    }
                    // else: unrated, rating remains unchanged
                }
            }
            
            System.out.println(count);
        }
        
        br.close();
    }
}
