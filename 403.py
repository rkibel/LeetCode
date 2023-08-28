class Solution(object):
    def canCross(self, stones):
        d = dict([(value, index) for index, value in enumerate(stones)])
        dp = [[None for j in range(len(stones) + 1)] for i in range(len(stones) - 1)]

        def cross(stone, step):
            if stone == len(stones)-1: return True
            val = stones[stone]
            if step-1 > 0 and dp[stone][step-1] == None:
                dp[stone][step-1] = val+step-1 in d and cross(d[val+step-1], step-1)
            if step > 0 and dp[stone][step] == None:
                dp[stone][step] = val+step in d and cross(d[val+step], step) 
            if dp[stone][step+1] == None:
                dp[stone][step+1] = val+step+1 in d and cross(d[val+step+1], step+1)
            return dp[stone][step-1] or dp[stone][step] or dp[stone][step+1]
            
        return cross(0, 0)