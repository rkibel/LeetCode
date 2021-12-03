class Problem1(object):
    def twoSum(self, nums, target):
        for i, val1 in enumerate(nums):
            if target-val1 in nums[i+1:]:
                return [i, nums[i+1:].index(target-val1) + i + 1]