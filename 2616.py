class Solution(object):
    def minimizeMax(self, nums, p):        
       
        def works(val):
            c = i = 0
            while i < len(nums)-1 and c < p:
                if nums[i+1] - nums[i] <= val: 
                    c += 1
                    i += 2
                else: i += 1
            return c >= p
        
        nums.sort()
        left, right = 0, nums[-1] - nums[0]
        while left <= right:
            mid = (left+right) // 2
            if works(mid): right = mid - 1
            else: left = mid + 1
        
        return left
        