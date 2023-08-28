class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        tot, index, prod = 0, 0, 1
        for i, num in enumerate(nums):
            prod *= num
            while prod >= k and index < i:
                prod //= nums[index]
                index += 1
            if prod < k: tot += i-index+1
        return tot