class Solution(object):
    def productExceptSelf(self, nums):
        lprod = []
        mul = 1
        for num in nums:
            mul *= num
            lprod.append(mul)
        rprod = []
        mul = 1
        for num in reversed(nums):
            mul *= num
            rprod.insert(0, mul)
        res = [rprod[1]]
        for i in range(1, len(nums)-1):
            res.append(lprod[i-1] * rprod[i+1])
        res.append(lprod[len(nums)-2])
        return res