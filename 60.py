import math
class Solution(object):
    def getPermutation(self, n, k):
        if n == 1: return "1"
        nums = [i+1 for i in range(n)]
        res = ""
        for i in range(n, 2, -1):
            fac = math.factorial(i-1)
            index = (k-1) / fac
            res += str(nums[index])
            nums.pop(index)
            k -= fac * index
        return res + str(nums[1]) + str(nums[0]) if k == 2 else \
               res + str(nums[0]) + str(nums[1])

        