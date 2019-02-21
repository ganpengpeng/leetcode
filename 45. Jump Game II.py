# class Solution:
#     def jump(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         VALUE_MAX = 9999999
#         length = len(nums)
#
#         if length <= 1:
#             return 0
#
#         rst = [VALUE_MAX] * length
#         rst[length - 1] = 1
#
#         for i in range(length - 1, -1, -1):
#             if i + nums[i] >= length - 1:
#                 rst[i] = 1
#             else:
#                 for j in range(i + 1, i + nums[i] + 1, 1):
#                     if rst[j] + 1 < rst[i]:
#                         rst[i] = rst[j] + 1
#         return rst[0]

class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length <= 1:
            return 0
        level = 0
        current_max = 0
        next_max = 0
        i = 0
        while current_max - i + 1 > 0:
            level += 1
            while i <= current_max:
                next_max = max(next_max, i + nums[i])
                if next_max >= length - 1:
                    return level
                i += 1
            current_max = next_max

solution = Solution()
nums = [x for x in range(25000, 0, -1)]
nums += [1, 0]
print(nums)
print(solution.jump(nums))
