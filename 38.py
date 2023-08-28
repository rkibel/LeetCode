class Solution(object):
    def countAndSay(self, n):
        if n == 1: return "1"
        ret = self.countAndSay(n-1)
        counter, temp, s = 1, ret[0], ""
        for char in ret[1:]:
            if char == temp: counter += 1
            else:
                s += str(counter) + temp
                counter = 1
                temp = char
        s += str(counter) + temp
        return s