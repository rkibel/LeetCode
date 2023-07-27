class Solution(object):
    def peakIndexInMountainArray(self, arr):
        lower = 0
        upper = len(arr)
        while lower < upper:
            med = int((lower + upper)/2)
            if med == 0:
                if arr[med+1] < arr[med]: return med
                lower = med+1
            elif med == len(arr)-1:
                if arr[med-1] < arr[med]: return med
                upper = med
            else:
                if arr[med-1] < arr[med] and arr[med+1] < arr[med]: return med
                elif arr[med-1] > arr[med]: upper = med
                else: lower = med+1
        return -1