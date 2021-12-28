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
    int depth = 0;
    int maxDepth(TreeNode* root) {
        traverse(root, 0);
        return depth;
    }
    void traverse(TreeNode* root, int d){
        if (root){
            depth = max(depth, d+1);
            traverse(root->right, d+1);
            traverse(root->left, d+1);
        }
    }
};