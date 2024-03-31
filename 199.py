# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        if root is None: return []
        res = [root.val]
        r = self.rightSideView(root.right)
        l = self.rightSideView(root.left)
        res.extend(r)
        res.extend(l[len(r):])
        return res