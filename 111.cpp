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
 
class Problem111 {
public:
    int depth = INT_MAX;
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        traverse(root, 1);
        return depth;
    }
    void traverse(TreeNode* root, int d){
        if (!root->left && !root->right) depth = min(depth, d);
        if (root->left) traverse(root->left, d+1);
        if (root->right) traverse(root->right, d+1);
    }
};