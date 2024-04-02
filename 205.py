class Solution(object):
    def isIsomorphic(self, s, t):
        if len(s) != len(t): return False
        sused = [None for i in range(256)]
        tused = [None for i in range(256)]
        for i in range(len(s)):
            sint, tint = (ord(s[i]), ord(t[i]))
            if sused[sint] is not None and sused[sint] != t[i]: return False
            if tused[tint] is not None and tused[tint] != s[i]: return False
            sused[sint], tused[tint] = t[i]
            tused[tint] = s[i]
        return True