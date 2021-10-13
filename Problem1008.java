/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import javax.swing.tree.*;
public class Problem1008 {
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = recursiveNode(preorder, 0, preorder.length-1);
        return root;
    }
    public TreeNode recursiveNode (int[] preorder, int start, int end){
        if (start > end)
            return null;
        TreeNode x = new TreeNode (preorder[start]);
        int index = start + 1;
        int val = preorder[start];
        while (index <= end && preorder[index] < val)
            index++;
        x.left = recursiveNode (preorder, start+1, index-1);
        x.right = recursiveNode (preorder, index, end);
        return x;
    }
}