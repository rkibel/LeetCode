class Solution(object):
    def topKFrequent(self, nums, k):
        d = dict()
        for num in nums:
            d[num] = d[num] + 1 if num in d else 1
        l = [[key, d[key]] for key in d.keys()]
        l.sort(key = lambda x: -x[1])
        return [l[a][0] for a in range(k)]

