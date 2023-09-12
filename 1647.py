class Solution(object):
    def minDeletions(self, s):
        freq = [0] * 26
        for char in s: freq[ord(char) - ord('a')] += 1
        s, news = set(), list()
        for f in freq:
            if f in s and f != 0: news.append(f)
            s.add(f)
        counter = 0
        for elem in news:
            j = elem-1
            while j > 0 and j in s: j-=1
            counter += elem-j
            s.add(j)
        return counter