class Solution(object):
    def findMaxLength(self, nums):
        found = dict()
        found[0] = -1
        s = maxLen = 0
        for i, num in enumerate(nums):
            s = s + 1 if num else s - 1
            if s in found: maxLen = max(maxLen, i - found[s])
            else: found[s] = i
        return maxLen