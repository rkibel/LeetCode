#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem563 {
public:
    int sum = 0;
    int findTilt(TreeNode* root) {
        if (root) dfs(root);
        return sum;
    }
    int dfs(TreeNode* root){
        int left = (root->left) ? dfs(root->left) : 0;
        int right = (root->right) ? dfs(root->right) : 0;
        sum += abs(left-right);
        return left + right + root->val;
    }
};