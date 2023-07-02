#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem94 {
public:
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return inorder;
    }
    void traverse(TreeNode* root){
        if (!root) return;
        if (root->left) traverse(root->left);
        inorder.push_back(root->val);
        if (root->right) traverse(root->right);
    }
};