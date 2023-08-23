from queue import PriorityQueue
class Solution(object):
    def reorganizeString(self, s):
        q = PriorityQueue()
        for i in range(ord('a'), ord('z')+1):
            c = s.count(chr(i))
            if c > 0: q.put((-c, chr(i)))
        
        string = ""
        while not q.empty():
            cnt1, item1 = q.get()
            if string != "" and string[-1] == item1:
                if q.empty(): return ""
                cnt2, item2 = q.get()
                q.put((cnt1, item1))
                cnt1, item1 = cnt2, item2
            string += item1
            cnt1 += 1
            if cnt1 != 0: q.put((cnt1, item1))

        return string