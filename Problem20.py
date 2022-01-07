class Problem20(object):
    def isValid(self, s):
        pre = ""
        def reverse(start, last):
            return (start == '(' and last == ')') or (start == '[' and last == ']') or (start == '{' and last == '}')
        for c in s:
            if c == '(' or c == '[' or c == '{': pre += c
            elif c == ')' or c == ']' or c == '}':
                if len(pre) == 0 or not reverse(pre[len(pre)-1], c): return False
                pre = pre[:-1]
        return len(pre) == 0