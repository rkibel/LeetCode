# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        arr = []
        while head:
            arr.append(head.val)
            head = head.next
        for i in range(len(arr) // 2):
            if arr[i] != arr[len(arr)-1-i]: return False
        return True
        