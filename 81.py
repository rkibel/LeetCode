class Solution(object):
    def search(self, nums, target):
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left+right) // 2
            if nums[right] == target or nums[left] == target or nums[mid] == target: return True
            if nums[left] == nums[mid] == nums[right]: 
                return self.search(nums[left+1:mid], target) or self.search(nums[mid+1:right], target)
            if nums[mid] <= nums[right]:
                if nums[mid] <= target <= nums[right]: left = mid+1
                else: right = mid-1
            else:
                if nums[left] <= target <= nums[mid]: right = mid-1
                else: left = mid+1
        return False
        