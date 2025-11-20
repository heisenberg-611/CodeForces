import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class B_Make_Connected{
    static class Cell {
        int r, c;
        Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            char[][] grid = new char[n][n];
            List<Cell> originalBlacks = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                grid[i] = br.readLine().toCharArray();
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == '#') {
                        originalBlacks.add(new Cell(i, j));
                    }
                }
            }
            
            // Condition 1: no black cell
            if (originalBlacks.isEmpty()) {
                System.out.println("YES");
                continue;
            }
            
            // Condition 2: check for "###" in input
            boolean hasThree = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= n - 3; j++) {
                    if (grid[i][j] == '#' && grid[i][j+1] == '#' && grid[i][j+2] == '#') {
                        hasThree = true;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int i = 0; i <= n - 3; i++) {
                    if (grid[i][j] == '#' && grid[i+1][j] == '#' && grid[i+2][j] == '#') {
                        hasThree = true;
                    }
                }
            }
            if (hasThree) {
                System.out.println("NO");
                continue;
            }
            
            // BFS to expand to safe white cells
            boolean[][] canBeBlack = new boolean[n][n];
            Queue<Cell> queue = new LinkedList<>();
            
            // Initialize with original black cells
            for (Cell cell : originalBlacks) {
                canBeBlack[cell.r][cell.c] = true;
                queue.offer(cell);
            }
            
            int[] dr = {1, -1, 0, 0};
            int[] dc = {0, 0, 1, -1};
            
            while (!queue.isEmpty()) {
                Cell cur = queue.poll();
                for (int d = 0; d < 4; d++) {
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (!canBeBlack[nr][nc]) {
                            // Temporarily mark as black
                            canBeBlack[nr][nc] = true;
                            if (!createsThree(nr, nc, canBeBlack, n)) {
                                queue.offer(new Cell(nr, nc));
                            } else {
                                // Revert
                                canBeBlack[nr][nc] = false;
                            }
                        }
                    }
                }
            }
            
            // Now check if all original black cells are in the same connected component
            boolean[][] visited = new boolean[n][n];
            Queue<Cell> dfsQueue = new LinkedList<>();
            Cell first = originalBlacks.get(0);
            dfsQueue.offer(first);
            visited[first.r][first.c] = true;
            
            while (!dfsQueue.isEmpty()) {
                Cell cur = dfsQueue.poll();
                for (int d = 0; d < 4; d++) {
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (canBeBlack[nr][nc] && !visited[nr][nc]) {
                            visited[nr][nc] = true;
                            dfsQueue.offer(new Cell(nr, nc));
                        }
                    }
                }
            }
            
            boolean allConnected = true;
            for (Cell cell : originalBlacks) {
                if (!visited[cell.r][cell.c]) {
                    allConnected = false;
                    break;
                }
            }
            
            System.out.println(allConnected ? "YES" : "NO");
        }
    }
    
    private static boolean createsThree(int i, int j, boolean[][] black, int n) {
        // Check row i: triplets that include column j
        for (int start = j - 2; start <= j; start++) {
            if (start >= 0 && start + 2 < n) {
                if (black[i][start] && black[i][start+1] && black[i][start+2]) {
                    return true;
                }
            }
        }
        // Check column j: triplets that include row i
        for (int start = i - 2; start <= i; start++) {
            if (start >= 0 && start + 2 < n) {
                if (black[start][j] && black[start+1][j] && black[start+2][j]) {
                    return true;
                }
            }
        }
        return false;
    }
}