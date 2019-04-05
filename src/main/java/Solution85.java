public class Solution85 {
    public int maximalRectangle(char[][] matrix) {
        int width = matrix.length;
        int longth = matrix[0].length;
        int[][] dp = new int[width][longth];
        if (matrix[0][0] == '0')
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for (int i = 1; i < longth; i++) {
            if (matrix[0][i] == '1')
                dp[0][i] = dp[0][i - 1] + 1;
            else
                dp[0][i] = 0;
        }
        for (int i = 1; i < width; i++) {
            if (matrix[i][0] == '1')
                dp[i][0] = dp[i-1][0] + 1;
            else
                dp[i][0] = 0;
        }
        for (int i = 1; i < width; i++) {
            for (int j = 1; j < longth; j++) {
                if (matrix[i][j] == '1')
                    dp[i][j] = dp[i-1][j - 1] + 1;
                else
                    dp[0][i] = 0;
            }
        }
        return 0;
    }
}
