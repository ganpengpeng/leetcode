public class Solution33 {
    public static void main(String[] args) {
        int[] nums = new int[]{4, 5, 6, 7, 0, 1, 2};
        Solution33 solution33 = new Solution33();
        System.out.println(solution33.search(nums, 0));
    }

    //    public int search(int[] nums, int target) {
//        int low = 0, high = nums.length - 1;
//        if (nums.length == 0) return -1;
//        if (nums.length == 1 && nums[0] == target) return 0;
//        while (low < high) {
//            // TODO trick
//            // low前进到mid+1，这样low可能会达到最小值的下标处，接着由于
//            // nums[mid]小于high，因此high每次都会变成mid的值
//            // 若mid每次都选到了有半部分，则high会减小到最小值下标处，然后
//            // 因为mid向下取整的原因，low会一直变成mid+1，直到等于high
//            int mid = (low + high) / 2;
//            if (nums[mid] > nums[high]) low = mid + 1;
//            else high = mid;
//        }
//        int minIndex = low;
//        if (nums[0] > nums[nums.length - 1]) {
//            if (target > nums[nums.length - 1]) {
//                int index = Arrays.binarySearch(nums, 0, minIndex, target);
//                return index < 0 ? -1 : index;
//            } else {
//                int index = Arrays.binarySearch(nums, minIndex, nums.length, target);
//                return index < 0 ? -1 : index;
//            }
//        } else {
//            int index = Arrays.binarySearch(nums, target);
//            return index < 0 ? -1 : index;
//        }
//    }
    //If nums[mid] and target are "on the same side" of nums[0], we just take nums[mid].
    public int search(int[] nums, int target) {
        for (int i = 0, j = nums.length - 1; i <= j; ) {
            int mid = (i + j) / 2;
            if (target == nums[mid]) return mid;
            if (nums[i] <= nums[mid]) {
                if (target >= nums[i] && target <= nums[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
}
