import java.util.Arrays;

public class Solution62 {
    public int uniquePaths(int m, int n) {
        int[] nums = new int[m];
        Arrays.fill(nums, 1);
        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j < nums.length; j++) {
                nums[j] += nums[j - 1];
            }
        }
        return nums[nums.length - 1];
    }
}
