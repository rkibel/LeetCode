class Solution(object):
    def searchRange(self, nums, target):
        if len(nums) == 0: return [-1, -1]

        def find(left, right, d):
            if left > right: return -1
            if left == right:
                if nums[left] == target: return left
                return -1
            mid = (left + right) // 2
            if nums[mid] < target: return find(mid+1, right, d)
            if nums[mid] > target: return find(left, mid-1, d)
            x = find(left, mid-1, d) if d else find(mid+1, right, d)
            return mid if x == -1 else x
        
        return [find(0, len(nums)-1, True), find(0, len(nums)-1, False)]
