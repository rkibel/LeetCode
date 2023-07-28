class Solution(object):
    def maxRunTime(self, n, batteries):
        batteries.sort()
        s = sum(batteries)
        i = len(batteries)-1
        while i >= 0 and s/n < batteries[i]:
            s -= batteries[i]
            n -= 1
            i -= 1
        return s/n