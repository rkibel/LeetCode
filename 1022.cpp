#include <string>
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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");
        return sum;
    }
    void traverse(TreeNode*root, string set){
        if (root->left) traverse(root->left, set+to_string(root->val));
        if (root->right) traverse(root->right, set+to_string(root->val));
        if (!root->left && !root->right) sum += stoi(set+to_string(root->val), 0, 2);
    }
};