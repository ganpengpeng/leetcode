public class Solution84 {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        if (len == 0) return 0;
        int maxArea = 0;
        for (int i = 0; i < len; i++) {
            int width = 0;
            int height = Integer.MAX_VALUE;
            for (int j = i; j >= 0; j--) {
                width += 1;
                height = Math.min(height, heights[j]);
                int area = width * height;
                maxArea = area > maxArea ? area : maxArea;
            }
        }
        return maxArea;
    }
}
