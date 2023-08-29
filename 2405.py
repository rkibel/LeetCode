class Solution(object):
    def partitionString(self, s):
        count = 0
        vals = [False] * 26
        for char in s:
            if vals[ord(char) - ord('a')]:
                vals = [False] * 26
                count += 1
            vals[ord(char) - ord('a')] = True
        return count+1