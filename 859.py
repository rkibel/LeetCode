class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): return False
        
        abc = [False] * 26
        containsDouble = False
        diff = list()

        for i, char in enumerate(s):
            if not containsDouble:
                val = ord(char)-97
                if abc[val]: containsDouble = True
                abc[val] = True
            
            if s[i] != goal[i]:
                if len(diff) == 2: return False
                diff.append(i)
        
        if len(diff) == 2:
            s = s[:diff[0]] + s[diff[1]] + s[diff[0]+1:diff[1]] + s[diff[0]] + s[diff[1]+1:]
            return s == goal
    
        return len(diff) == 0 and containsDouble