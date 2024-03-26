class Solution(object):
    def solveNQueens(self, n):
        res = []
        taken = [0 for i in range(n)]
        def backtrack(i):  
            if i == n: 
                res.append(["."*(val-1) + "Q" + "."*(n-val) for val in taken])
                return
            for j in range(1, n+1):
                works = True
                for it in range(i-1, -1, -1):
                    if j == taken[it] or abs(j-taken[it]) == i-it: 
                        works = False
                        break
                if works:
                    taken[i] = j
                    backtrack(i+1)
        backtrack(0)
        return res
