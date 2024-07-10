# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        dist = [-1, -1]
        firstCrit = prevCrit = None
        if not head: return dist
        prevVal = head.val
        head = head.next
        index = 1
        while(head and head.next):
            if (prevVal < head.val > head.next.val) or (prevVal > head.val < head.next.val):
                if firstCrit == None:
                    firstCrit = index
                    prevCrit = index
                else:
                    dist[1] = index - firstCrit
                    if dist[0] == -1: dist[0] = index - firstCrit
                    else: dist[0] = min(dist[0], index - prevCrit)
                    prevCrit = index
            prevVal = head.val
            index += 1
            head = head.next
        return dist
        