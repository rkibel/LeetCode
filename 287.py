class Solution(object):
    def findDuplicate(self, nums):
        for i in range(len(nums)):
            index = abs(nums[i])
            if nums[index] < 0: return index
            nums[index] = -nums[index]
        return -1
        