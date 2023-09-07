class RecentCounter(object):

    def __init__(self):
        self.arr = []

    def ping(self, t):
        while len(self.arr) > 0 and self.arr[0] < t-3000: self.arr.pop(0)
        self.arr.append(t)
        return len(self.arr)