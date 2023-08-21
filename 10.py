class Solution(object):
    def isMatch(self, s, p):
        indices = [i for i, c in enumerate(p) if c == "*"]  
        for i in (reversed(range(len(indices)-1))):
            first, second = indices[i], indices[i+1]
            if first + 2 == second and p[first-1] == p[second-1]: p = p[0:first] + p[first+2:]

        def match(s, p):
            if len(p) == 0: return len(s) == 0
            if p.isalpha(): return s == p
            if len(p) == 1: return len(s) == 1 
            if p[1] == '*':
                if p[0] == '.': return any(match(s[i:], p[2:]) for i in range(0, len(s)+1))
                if match(s, p[2:]): return True
                i = 0
                while i < len(s) and s[i] == p[0]:
                    i += 1
                    if match(s[i:], p[2:]): return True
                return False
            if len(s) == 0: return False
            if p[0] != '.' and s[0] != p[0]: return False
            return match(s[1:], p[1:])
        
        return match(s, p)