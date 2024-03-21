class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        sums = {0: 1}
        res = 0
        s = 0
        for num in nums:
            s += num
            if s >= goal and s - goal in sums:
                res += sums[s-goal]
            sums[s] = sums[s] + 1 if s in sums else 1
        return res