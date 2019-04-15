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
            // TODO trick
            // switch pos and neg when num[i] < 0
            if (nums[i] < 0) {
                int tmp = pos;
                pos = neg;
                neg = tmp;
            }
            // use max function to choose max value between nums[i] and pos*nums[i]
            pos = Math.max(nums[i], pos * nums[i]);
            neg = Math.min(nums[i], neg * nums[i]);
            max = Math.max(max, pos);
        }
        return max;
    }
}
