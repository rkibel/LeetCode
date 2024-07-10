class Problem1823(object):
    def findTheWinner(self, n, k):
        arr = [i+1 for i in range(n)]
        currIndex = 0
        for i in range(n-1):
            currIndex = (currIndex + (k-1)) % len(arr)
            arr.pop(currIndex)
        return arr[0]
        