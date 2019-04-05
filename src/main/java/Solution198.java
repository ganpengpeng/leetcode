public class Solution198 {
    public int rob(int[] nums) {
        if (nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        int first = nums[0], second = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            int fi = Math.max(second, first+nums[i]);
            first = second;
            second = fi;
        }
        return second;
    }
}
