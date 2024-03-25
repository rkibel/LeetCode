class Solution(object):
    def permuteUnique(self, nums):
        res = []
        finished = []
        taken = [False for num in nums]
        def back():
            if len(finished) == len(nums):
                res.append(finished[:])
                return
            used = set()
            for i in range(len(nums)):
                if not taken[i] and nums[i] not in used:
                    finished.append(nums[i])
                    used.add(nums[i])
                    taken[i] = True
                    back()
                    taken[i] = False
                    finished.pop()
        back()
        return res
        