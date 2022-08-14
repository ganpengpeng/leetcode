import numpy as np


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        # 动态规划
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        rst = np.zeros([m, n])
        if obstacleGrid[0][0] == 1:
            return 0
        rst[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i > 0 and obstacleGrid[i][j] != 1:
                    rst[i][j] += rst[i - 1][j]
                if j > 0 and obstacleGrid[i][j] != 1:
                    rst[i][j] += rst[i][j - 1]
        return int(rst[-1][-1])


obstacleGrid = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
s = Solution()
s.uniquePathsWithObstacles(obstacleGrid)
