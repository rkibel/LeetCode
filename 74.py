class Solution(object):
    def searchMatrix(self, matrix, target):
        up, down = 0, len(matrix)-1
        while up < down:
            mid = (up+down) // 2
            if matrix[mid][0] > target: down = mid
            elif matrix[mid][-1] < target: up = mid+1
            else: up = down = mid
        if up >= len(matrix) or up < 0: return False
        left, right = 0, len(matrix[0])-1
        while left <= right:
            mid = (left+right) // 2
            if matrix[up][mid] == target: return True
            elif matrix[up][mid] < target: left = mid+1
            else: right = mid-1
        return False 