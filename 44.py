class Solution(object):
    def isMatch(self, string, pattern):
        for i in reversed(range(len(pattern)-1)):
            if pattern[i+1] == pattern[i] == '*': 
                pattern = pattern[0:i] + pattern[i+1:]
        dp = [[None for i in pattern] for j in string]                

        def match(i, j):
            if j == len(pattern): return i == len(string)
            if i == len(string): return pattern[j:] == '*'
            if dp[i][j] != None: return dp[i][j]

            s, p = string[i:], pattern[j:]
            dp[i][j] = p.isalpha() and s == p \
            or p[0] == '*' and any(match(k, j+1) for k in range(i, len(string)+1)) \
            or (p[0] == '?' or p[0] == s[0]) and match(i+1, j+1)
            return dp[i][j]   

        return match(0, 0)