class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        track1 = track2 = 0
        res = []
        while track1 < len(firstList) and track2 < len(secondList):
            arr1, arr2 = firstList[track1], secondList[track2]
            if not arr1[1] < arr2[0] and not arr2[1] < arr1[0]: 
                res.append([max(arr1[0], arr2[0]), min(arr1[1], arr2[1])])
            (track2, track1) = (track2 + 1, track1) if arr1[1] >= arr2[1] else (track2, track1 + 1)
        return res
        