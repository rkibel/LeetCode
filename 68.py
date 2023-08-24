class Solution(object):
    def fullJustify(self, words, maxWidth):
        index = 0
        res = []
        while index < len(words):
            lastline = (index == len(words) - 1)
            arr = [words[index]]
            tot = len(words[index])
            index += 1
            while index < len(words) and tot + len(arr) + len(words[index]) <= maxWidth:
                tot += len(words[index])
                arr.append(words[index])
                if index == len(words)-1: lastline = True
                index += 1
            s = ""
            if len(arr) == 1: 
                s = arr[0] + (" " * (maxWidth-tot))
            elif lastline:
                s = ' '.join(arr) + (" " * (maxWidth-tot-(len(arr)-1)))
            else:
                quotient, remainder = divmod(maxWidth-tot, len(arr)-1)
                for i in range(len(arr)-1):
                    s += arr[i] + (" " * quotient)
                    if i < remainder: s += " "
                s += arr[-1]
            res.append(s)
        return res