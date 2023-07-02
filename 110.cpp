#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(findLen(root->left) - findLen(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int findLen(TreeNode* root){
        if (!root) return 1;
        return max(findLen(root->right), findLen(root->left)) + 1;
    }
};