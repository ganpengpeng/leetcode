public class Solution169 {
    public int majorityElement(int[] nums) {
        int count = 0;
        int ele = 0;
        for ( int i = 0; i < nums.length; i++) {
            if (count == 0) {
                count += 1;
                ele = nums[i];
            } else if (nums[i] == ele) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return ele;
    }
}
