class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        if head == None: return None
        m = {None:None}
        h = Node(head.val)
        m[head] = it = h
        temp = head.next
        while temp != None:
            m[temp] = it.next = Node(temp.val)
            it = it.next
            temp = temp.next
        
        m[head].random = m[head.random]
        temp = head.next
        while temp != None:
            m[temp].random = m[temp.random]
            temp = temp.next
        
        return h

        