class Solution(object):
    def minTaps(self, n, ranges):
        rang = sorted([(i-r, i+r) for i, r in enumerate(ranges)], key=lambda tup: tup[0])

        counter = left = water = 0
        while left < len(rang) and water < n:
            maxright, index = water, None
            for i in range(left, len(rang)):
                if rang[i][0] <= water and rang[i][1] >= maxright:
                    maxright, index = rang[i][1], i
            if index == None: return -1
            counter += 1
            left = index+1
            water = maxright
        
        return counter if water >= n else -1