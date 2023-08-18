class Solution(object):
    def maximalNetworkRank(self, n, roads):
        out = [(i, 0) for i in range(n)]
        hasRoad = [[False for i in range(n)] for j in range(n)]
        for road in roads:
            a, b = road[0], road[1]
            out[a] = (a, out[a][1] + 1)
            out[b] = (b, out[b][1] + 1)
            hasRoad[a][b] = hasRoad[b][a] = True
        out.sort(key = lambda x: x[1], reverse=True)
        maxLen = out[0][1] + out[1][1] if not hasRoad[out[0][0]][out[1][0]] else out[0][1] + out[1][1] - 1
        for i in range(2, n):
            s = out[0][1] + out[i][1] if not hasRoad[out[0][0]][out[i][0]] else out[0][1] + out[i][1] - 1
            if s < maxLen - 1: break
            if n > 2:
                s = max(s, out[1][1] + out[i][1] if not hasRoad[out[1][0]][out[i][0]] else out[1][1] + out[i][1] - 1)
                if s < maxLen - 1: break
                maxLen = max(maxLen, s)
        return maxLen
