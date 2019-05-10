import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution15 {
    public static void main(String[] args) {
        Solution15 solution15 = new Solution15();
        int[] nums = new int[]{-1, 0, 1, 2, -1, -4};
        solution15.threeSum(nums);
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> rst = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            int target = 0 - nums[i];
            for (int j = i + 1, k = nums.length - 1; j < k; ) {
                if (nums[j] + nums[k] == target) {
                    ArrayList<Integer> triple = new ArrayList<>();
                    triple.add(nums[i]);
                    triple.add(nums[j]);
                    triple.add(nums[k]);
                    rst.add(triple);
                    while(j < k && nums[j] == nums[j + 1]) j += 1;
                    while(j < k && nums[k] == nums[k - 1]) k -= 1;
                    j += 1;
                    k -= 1;
                } else if (nums[j] + nums[k] > target) {
                    k -= 1;
                } else {
                    j += 1;
                }
            }
            while(i + 1 < nums.length && nums[i] == nums[i + 1]) i += 1;
        }
        return rst;
    }
}
