class Solution(object):
    def findDuplicates(self, nums):
        arr = []
        for i in range(len(nums)):
            index = abs(nums[i])
            if nums[index-1] < 0: arr.append(index)
            nums[index-1] *= -1
        return arr
        