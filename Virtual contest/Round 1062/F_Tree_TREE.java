import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class F_Tree_TREE{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            List<Integer>[] adj = new List[n + 1];
            for (int i = 1; i <= n; i++) {
                adj[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                adj[u].add(v);
                adj[v].add(u);
            }

            int[] subtreeSize = new int[n + 1];
            int[] parent = new int[n + 1];
            
            // DFS from node 1
            dfs(1, -1, adj, subtreeSize, parent);

            long total = 0;
            int threshold = n - k; // component size must be <= threshold

            for (int v = 1; v <= n; v++) {
                long count = 1; // root at v itself

                // Parent component (if exists)
                if (parent[v] != -1) {
                    int parentComp = n - subtreeSize[v];
                    if (parentComp <= threshold) {
                        count += parentComp;
                    }
                }

                // Child components
                for (int child : adj[v]) {
                    if (child == parent[v]) continue;
                    int childComp = subtreeSize[child];
                    if (childComp <= threshold) {
                        count += childComp;
                    }
                }

                total += count;
            }

            sb.append(total).append('\n');
        }

        System.out.print(sb);
    }

    static void dfs(int u, int p, List<Integer>[] adj, int[] subtreeSize, int[] parent) {
        parent[u] = p;
        subtreeSize[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, adj, subtreeSize, parent);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}