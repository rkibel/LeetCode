class Solution:
    def totalNQueens(self, n: int) -> int:
        res = 0
        midsoln = 0
        taken = [0 for i in range(n)]
        def backtrack(i):
            nonlocal res, midsoln
            if i == n: 
                if n % 2 == 1 and taken[0] == n // 2 + 1: midsoln += 1
                else: res += 1
                return
            bounds = (n+1) // 2 if i == 0 else n
            for j in range(1, bounds+1):
                works = True
                for it in range(i-1, -1, -1):
                    if j == taken[it] or abs(j-taken[it]) == i-it: 
                        works = False
                        break
                if works:
                    taken[i] = j
                    backtrack(i+1)
        backtrack(0)
        return 2*res + midsoln