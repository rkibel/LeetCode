import javax.swing.tree.TreeNode;

import javax.swing.*;
public class Problem543 {
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
    int counter = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        height (root);
        return counter;    
    }
    public int height (TreeNode root){
        if (root == null)
            return 0;
        int l = height (root.left);
        int r = height(root.right);
        counter = Math.max(counter, l + r);
        return Math.max(r, l) + 1;
    }
}

