class Solution(object):
    def minExtraChar(self, s, dictionary):
        dp = [0]*(len(s)+1)
        for i in reversed(range(len(s))):
            dp[i] = 1 + dp[i+1]
            for word in dictionary:
                if s[i:].startswith(word): 
                    dp[i] = min(dp[i], dp[i+len(word)])        
        return dp[0]