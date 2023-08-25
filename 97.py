class Solution(object):
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3): return False
        dp = [[None for i in range(len(s2)+1)] for j in range(len(s1)+1)]
        dp[-1][-1] = True

        def getInterleave(index1, index2):
            if index1 > len(s1) or index2 > len(s2): return False
            if dp[index1][index2] != None: return dp[index1][index2]
            
            test1 = s1[index1:]
            test2 = s2[index2:]
            test3 = s3[(index1 + index2):]

            dp[index1][index2] = \
                (len(test3) == 0 and len(test2) == 0 and len(test1) == 0) or \
                (len(test1) == 0 and test2 == test3) or \
                (len(test2) == 0 and test1 == test3) \
                if (len(test3) == 0 or len(test1) == 0 or len(test2) == 0) else \
                (test3[0] == test1[0] and getInterleave(index1 + 1, index2)) or \
                (test3[0] == test2[0] and getInterleave(index1, index2 + 1))
            return dp[index1][index2]
        
        return getInterleave(0, 0)