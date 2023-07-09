class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        order = list()
        m, n, = (len(matrix), len(matrix[0]))
        top, right, bottom, left = (-1, n, m, -1)
        
        i, j = 0, 0
        order.append(matrix[i][j])
        while len(order) < m*n:
            for jnew in range(j+1, right):
                j = jnew
                order.append(matrix[i][j])
                if len(order) >= m*n: return order
            top += 1
            for inew in range(i+1, bottom):
                i = inew
                order.append(matrix[i][j])
                if len(order) >= m*n: return order
            right -= 1
            for jnew in range(j-1, left, -1):
                j = jnew
                order.append(matrix[i][j])
                if len(order) >= m*n: return order
            bottom -= 1
            for inew in range(i-1, top, -1):
                i = inew
                order.append(matrix[i][j])
                if len(order) >= m*n: return order
            left += 1

        return order
