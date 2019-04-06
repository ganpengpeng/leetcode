import java.util.Arrays;

public class Solution85 {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0)
            return 0;
        int n = matrix.length;
        int m = matrix[0].length;
        int[] height = new int[m];
        int[] left = new int[m];
        int[] right = new int[m];
        int result = 0;
        Arrays.fill(right, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j] = height[j] + 1;
                } else {
                    height[j] = 0;
                }
            }
            int curLeft = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = Math.max(left[j], curLeft);
                } else {
                    curLeft = j + 1;
                    left[j] = 0;
                }
            }
            int curRight = m;
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = Math.min(right[j], curRight);
                } else {
                    curRight = j;
                    right[j] = m;
                }
            }
            for (int j = 0; j < m; j++) {
                int area = height[j] * (right[j] - left[j]);
                result = result < area ? area : result;
            }
        }
        return result;
    }
}
