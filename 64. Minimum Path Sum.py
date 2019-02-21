class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        for i in range(1, m):
            grid[i][0] += grid[i - 1][0]
        for i in range(1, n):
            grid[0][i] += grid[0][i - 1]
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += grid[i - 1][j] if grid[i - 1][j] < grid[i][j - 1] \
                    else grid[i][j - 1]
        return grid[m - 1][n - 1]


grid = [
    [1, 3, 1],
    [1, 5, 1],
    [4, 2, 1]
]
s = Solution()
s.minPathSum(grid)
