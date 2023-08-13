class Solution(object):
    def validPartition(self, nums):
        dp = [None] * len(nums)

        def isValid(i):
            if i >= len(dp): return True
            if dp[i] != None: return dp[i]
            dp[i] = (i < len(nums)-1 and nums[i] == nums[i+1] and isValid(i+2)) \
            or (i < len(nums)-2 and nums[i]==nums[i+1]==nums[i+2] and isValid(i+3)) \
            or (i < len(nums)-2 and nums[i] + 2 == nums[i+1] + 1 == nums[i+2] and isValid(i+3))
            return dp[i]
        
        return isValid(0)