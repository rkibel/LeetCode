class Solution(object):
    def isValidSudoku(self, board):
        for row in board:
            arr = [False] * 9
            for elem in row:
                if elem != '.':
                    if arr[int(elem)-1]: return False
                    arr[int(elem)-1] = True
        
        for j in range(len(board[0])):
            arr = [False] * 9
            for i in range(len(board)):
                if board[i][j] != '.':
                    if arr[int(board[i][j]) - 1]: return False
                    arr[int(board[i][j]) - 1] = True
        
        row, col = 0, 0
        for i in range(1, 10):
            arr = [False] * 9
            for j in range(3):
                for k in range(3):
                    if board[row+j][col+k] != '.':
                        if arr[int(board[row+j][col+k]) - 1]: return False
                        arr[int(board[row+j][col+k]) - 1] = True
            if i % 3 == 0:
                row += 3
                col = 0
            else: col += 3
        
        return True
