class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 把数值放在列表的相应位置，如2放在下标为1，也就是列表的第二个数
        # 遍历列表，返回第一个下标不匹配的
        length = len(nums)
        if length == 0:
            return 1
        for i in range(length):
            while 0 < nums[i] <= length and nums[i] != i + 1:
                tmp = nums[i]
                # break when tmp == nums[tmp - 1]
                # example: [1, 1]
                if tmp == nums[tmp - 1]:
                    break
                nums[i] = nums[tmp - 1]
                nums[tmp - 1] = tmp
        for i in range(length):
            if nums[i] != i + 1:
                return i + 1
        return length + 1


solution = Solution()
nums = [3, 4, -1, 1]
solution.firstMissingPositive(nums)
