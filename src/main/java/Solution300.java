public class Solution300 {
    public static void main(String[] args) {
        Solution300 solution300 = new Solution300();
        System.out.println(solution300.lengthOfLIS(new int[]{10, 9, 2, 5, 3, 7, 101, 18}));

    }

    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0)
            return 0;
        int[] dp = new int[nums.length];
        int globalMax = 0;
        for (int i = 0; i < nums.length; i++) {
            int max = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    max = max < dp[j] ? dp[j] : max;
                }
            }
            dp[i] = max + 1;
            globalMax = globalMax < dp[i] ? dp[i] : globalMax;
        }
        return globalMax;
    }
}
