class Solution(object):
    def longestConsecutive(self, nums):
        if len(nums) == 0: return 0
        d = dict()
        for num in nums: d[num] = False
        length = 1
        for num in nums:
            if d[num]: continue
            d[num] = True
            currLength = 1
            it = num+1
            while it in d:
                d[it] = True
                currLength += 1
                it += 1
            it = num-1
            while it in d:
                d[it] = True
                currLength += 1
                it -= 1
            length = max(length, currLength)            
        return length
        