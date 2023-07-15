class Solution(object):
    def maxValue(self, events, k):
        events.sort(key = lambda x: x[0])
        dp = [[-1 for i in range(k+1)] for event in events]
        def getValue(i, j, currDay):
            if i == len(events) or j == 0: return 0
            start, end, value = events[i] 
            if start <= currDay: return getValue(i+1, j, currDay)
            if dp[i][j] != -1: return dp[i][j]
            dp[i][j] = max(value + getValue(i+1, j-1, end), getValue(i+1, j, currDay))
            return dp[i][j]
        return getValue(0, k, 0)