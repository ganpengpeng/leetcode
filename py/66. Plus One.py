class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        length = len(digits)
        digits[length - 1] += 1
        index = length - 1
        while index >= 0 and digits[index] > 9:
            if index == 0:
                digits[0] = 0
                digits.insert(0, 1)
            else:
                digits[index] = 0
                index -= 1
                digits[index] += 1
        return digits


solution = Solution()
print(solution.plusOne([9]))
