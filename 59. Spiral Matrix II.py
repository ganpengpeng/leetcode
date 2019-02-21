class Solution:
    def generateMatrix(self, n):
        rst = [[0] * n for _ in range(n)]
        count = 1
        i = j = 0
        while count <= n * n:
            while rst[i][j % n] == 0:
                rst[i][j % n] = count
                count += 1
                j += 1
            j -= 1
            i += 1
            while rst[i % n][j] == 0:
                rst[i % n][j] = count
                count += 1
                i += 1
            i -= 1
            j -= 1
            while rst[i][j % n] == 0:
                rst[i][j % n] = count
                count += 1
                j -= 1
            j += 1
            i -= 1
            while rst[i % n][j] == 0:
                rst[i % n][j] = count
                count += 1
                i -= 1
            i += 1
            j += 1
        return rst

    def generateMatrix(self, n):
        A = [[0] * n for _ in range(n)]
        i, j, di, dj = 0, 0, 0, 1
        for k in range(n * n):
            A[i][j] = k + 1
            if A[(i + di) % n][(j + dj) % n]:
                di, dj = dj, -di
            i += di
            j += dj
        return A


solution = Solution()
n = 3
print(solution.generateMatrix(n))
