from collections import defaultdict
class Solution(object):
    def groupAnagrams(self, strs):
        hashes = defaultdict(list)
        for string in strs:
            arr = [0 for i in range(26)]
            for char in string:
                arr[ord(char) - ord('a')] += 1
            h = hash(tuple(arr))
            hashes[h].append(string)
        return list(hashes.values())
        