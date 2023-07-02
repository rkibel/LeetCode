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
#include <cmath>;
class Problem222 {
public:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        TreeNode* tl = root, *tr = root;
        int height_l = 0, height_r = 0;
        while (tl){
            tl = tl->left;
            height_l++;
        }
        while (tr){
            tr = tr->right;
            height_r++;
        }
        if (height_l == height_r)
            return pow(2, height_r) - 1;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};