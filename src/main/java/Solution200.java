public class Solution200 {
    int m = 0;
    int n = 0;

    public int numIslands(char[][] grid) {
        if (grid.length == 0) return 0;
        m = grid.length;
        n = grid[0].length;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    DFSMarking(grid, i, j);
                    count += 1;
                }
            }
        }
        return count;
    }

    public void DFSMarking(char[][] grid, int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1') {
            grid[i][j] = '0';
            DFSMarking(grid, i - 1, j);
            DFSMarking(grid, i, j - 1);
            DFSMarking(grid, i + 1, j);
            DFSMarking(grid, i, j + 1);
        }
    }
}
