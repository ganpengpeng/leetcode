public class Solution33 {
    public static void main(String[] args) {
        int[] nums = new int[]{4, 5, 6, 7, 8, 1, 2, 3};
        Solution33 solution33 = new Solution33();
        solution33.search(nums, 8);
        System.out.println(solution33.search(nums, 0));
    }

    public int search(int[] nums, int target) {
        for (int i = 0, j = nums.length - 1; i < j; ) {
            int mid = (i + j) / 2;
            if (target < nums[mid]) {
                if (target >= nums[i]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else if (target > nums[mid]) {
                if (target > nums[j]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else {
                return mid;
            }
        }
        return -1;
    }
}
