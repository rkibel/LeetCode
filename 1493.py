import List
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        if len(nums) == 1: return 0
        temp = list()
        for num in nums:
            if num == 1:
                if len(temp) == 0 or temp[-1] == 0:
                    temp.append(1)
                else:
                    temp[-1] += 1
            else:
                temp.append(0)
        res = 0
        for i in range(len(temp)):
            if temp[i] != 0:
                res = max(res, temp[i] - 1)
            else:
                if i == 0:
                    res = max(res, temp[i+1])
                elif i == len(temp) - 1:
                    res = max(res, temp[i-1])
                else:
                    res = max(res, temp[i-1] + temp[i+1])
        return res

        
