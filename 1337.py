import numpy as np
from operator import itemgetter
class Solution(object):
    def kWeakestRows(self, mat, k):
        return np.array(sorted([[i, arr.count(1)] for i, arr in enumerate(mat)], key=itemgetter(1,0)))[:k, 0]