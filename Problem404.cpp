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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Problem404 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false, 0);   
    }
    int dfs(TreeNode* root, bool isLeft, int cur){
        if (!root)
            return 0;
        if (isLeft && !root->left && !root->right)
            return cur + root->val;
        return dfs(root->left, true, cur) + dfs(root->right, false, cur);
    }
};