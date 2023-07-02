import List
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = list()
        wordlen = len(words[0])
        strlen = wordlen * len(words)

        def fits(wordAvailable, index, counter):
            nonlocal s, wordlen, words

            if counter == len(words): return True
            substr = s[index:index + wordlen]
            for i, word in enumerate(words):
                if wordAvailable[i] and word == substr: 
                    wordAvailable[i] = False
                    return fits(wordAvailable, index + wordlen, counter + 1)
            return False

        for i in range(len(s) - strlen + 1):
            wordAvailable = [True for word in words]
            if fits(wordAvailable, i, 0): ans.append(i)
        return ans

