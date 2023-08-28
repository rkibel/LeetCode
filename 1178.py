class Solution(object):
    def findNumOfValidWords(self, words, puzzles):
        def mask(s):
            mask = 0
            for char in s: mask |= 1 << (ord(char)-ord('a'))
            return mask
        
        m = dict()
        for word in words:
            x = mask(word)
            m[x] = m[x] + 1 if x in m else 1
        
        res = []
        for puzzle in puzzles:
            y = mask(puzzle)
            count, itr, first = 0, y, 1 << ord(puzzle[0]) - ord('a')
            while itr:
                if itr & first and itr in m: count += m[itr]
                itr = (itr-1) & y
            res.append(count)
        
        return res