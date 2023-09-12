from functools import reduce
class Solution(object):
    def countOrders(self, n):
        return reduce(lambda x, i: x * (2 * i - 1) * i % (10**9 + 7), range(2, n+1), 1)