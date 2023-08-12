class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[-1 if x == 0 else 0 for x in row] for row in obstacleGrid]
        if dp[0][0] != 0: dp[0][0] = 1
        def getPaths(i, j):
            if i < 0 or j < 0: return 0
            if dp[i][j] != -1: return dp[i][j]
            dp[i][j] = getPaths(i-1, j) + getPaths(i, j-1)
            return dp[i][j]
        return getPaths(m-1, n-1)