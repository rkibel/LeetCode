class Solution(object):
    def minRemoveToMakeValid(self, s):
        stack = []
        res = list(s)
        for i, char in enumerate(res):
            if char == ')':
                if len(stack) == 0: 
                    res[i] = '*'
                else: 
                    res[stack[-1]] = '('
                    stack.pop()
            elif char == '(': 
                res[i] = '*'
                stack.append(i)
        return ''.join(char for char in res if char != '*')
        