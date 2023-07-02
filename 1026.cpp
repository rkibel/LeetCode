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
    int diff = 0;
    int maxAncestorDiff(TreeNode* root) {
        if (root->left) maxDiff(root->left, root->val, root->val);
        if (root->right) maxDiff(root->right, root->val, root->val);
        return diff;
    }
    void maxDiff (TreeNode* root, int MIN, int MAX){
        MIN = min(MIN, root->val);
        MAX = max(MAX, root->val);
        diff = max(diff, MAX-MIN);
        if (root->left) maxDiff(root->left, MIN, MAX);
        if (root->right) maxDiff(root->right, MIN, MAX);
    }
};