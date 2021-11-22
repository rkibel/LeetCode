/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        traverseTree(root, key);
        return root;
    }
    void traverseTree(TreeNode*& curr, int key){
        if (curr->val == key){
            deleter(curr);
            return;
        }
        if (curr->left)
            traverseTree(curr->left, key);
        if (curr->right)
            traverseTree(curr->right, key);
    }
    void deleter (TreeNode*& found){
        if (found->right){
            found->val = found->right->val;
            found->right = found->right->right;
        }
        else if (found->left){
            found->val = found->left->val;
            found->left = found->left->left;
        }
        else{
            found = nullptr;
        }
    }
};