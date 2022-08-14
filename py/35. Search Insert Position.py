class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # 简单的二分搜索
        size = len(nums)
        first = 0
        last = size - 1
        while first < last:
            mid = (first + last) // 2
            if nums[mid] == target:
                last = mid - 1
            elif nums[mid] > target:
                last = mid - 1
            else:
                first = mid + 1
        if nums[first] < target:
            return first + 1
        else:
            return first


solution = Solution()
nums = []
target = 1
solution.searchInsert(nums, target)
