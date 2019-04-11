public class Solution152 {
    public int maxProduct(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        int pos = nums[0];
        int neg = nums[0];
        int max = nums[0];
//        if (nums[0] > 0){
//            pos = nums[0];
//        }else if (nums[0] < 0){
//            neg = nums[0];
//        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {
                int tmp = pos;
                pos = neg;
                neg = tmp;
            }
            pos = Math.max(nums[i], pos * nums[i]);
            neg = Math.min(nums[i], neg * nums[i]);
            max = Math.max(max, pos);
        }
        return max;
    }
}
