class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)
        for p in range(n // 2):
            i, j = (p, p)
            for m in range(n- 2*p - 1):
                temp = matrix[i][j]
                for k in range(4):
                    inew, jnew = (j, n-1-i)
                    matrix[inew][jnew], temp = (temp, matrix[inew][jnew])
                    i, j = (inew, jnew)
                j += 1
        return matrix