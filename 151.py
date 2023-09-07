class Solution(object):
    def reverseWords(self, s):
        return ' '.join(reversed(filter(lambda x: len(x) != 0, s.split(' '))))