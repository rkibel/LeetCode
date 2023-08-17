class Solution(object):
    def updateMatrix(self, mat):
        m, n = len(mat), len(mat[0])
        queue = []
        res = [[-1 for j in range(n)] for i in range(m)]
        for i, row in enumerate(mat):
            for j, elem in enumerate(row):
                if elem == 0: 
                    res[i][j] = 0
                    queue.append((i, j, 0))
        while len(queue) != 0:
            i, j, l = queue.pop(0)
            if res[i][j] == -1: res[i][j] = l
            if i < m-1 and res[i+1][j] == -1: queue.append((i+1, j, l+1))
            if i > 0 and res[i-1][j] == -1: queue.append((i-1, j, l+1))
            if j < n-1 and res[i][j+1] == -1: queue.append((i, j+1, l+1))
            if j > 0 and res[i][j-1] == -1: queue.append((i, j-1, l+1))
        return res