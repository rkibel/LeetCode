import random
class Solution(object):
    def findKthLargest(self, nums, k):
        left, right = 0, len(nums)-1
        while True:
            pivot = random.randint(left, right)
            val = nums[pivot]
            nums[pivot], nums[right] = nums[right], nums[pivot]
            i = left
            for j in range(left, right):
                if nums[j] < val:
                    nums[j], nums[i] = nums[i], nums[j]
                    i+=1
            nums[right], nums[i] = nums[i], nums[right]
            if i == len(nums) - k: return nums[i]
            elif i > len(nums) - k: right = i-1
            else: left = i+1
        
        raise Exception("TLE - something happened")

