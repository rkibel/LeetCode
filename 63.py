class Solution(object):
    def uniquePathsWithObstacles(self, obs):
        if obs[0][0]: return 0
        dp = [[1-x for x in row] for row in obs]
        for i in range(len(obs)):
            for j in range(len(obs[0])):
                if (i == 0 and j == 0) or not dp[i][j]: continue
                if i == 0: dp[i][j] = dp[i][j-1]
                elif j == 0: dp[i][j] = dp[i-1][j]
                else: dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]