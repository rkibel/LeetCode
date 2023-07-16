class Solution(object):
    def longestSubsequence(self, arr, difference):
        dp = {}
        ans = 0
        for i, num in enumerate(arr):
            dp[num] = dp[num-difference] + 1 if num - difference in dp else 1
            ans = max(ans, dp[num])
        return ans
