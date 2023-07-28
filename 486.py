class Solution(object):
    def PredictTheWinner(self, nums):
        dp = [[None for j in nums] for i in nums]
        def getWinner(i, j):
            if dp[i][j] != None: return dp[i][j]
            if i == j:
                dp[i][j] = nums[i]
            else:
                dp[i][j] = max(nums[i] - getWinner(i+1, j), nums[j] - getWinner(i, j-1))
            return dp[i][j]
        return getWinner(0, len(nums)-1) >= 0