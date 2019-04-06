public class Solution84 {

    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if (len == 0) return 0;
        int maxArea = 0;
        int[] left = new int[len];
        int[] right = new int[len];
        left[0] = -1;
        for (int i = 1; i < len; i++) {
            int p = i - 1;
            while (p != -1 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }
        right[len - 1] = len;
        for (int i = len - 2; i >= 0; i--) {
            int p = i + 1;
            while (p != len && heights[i] <= heights[p]) {
                p = right[p];
            }
            right[i] = p;
        }
        for (int i = 0; i < len; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }
}
