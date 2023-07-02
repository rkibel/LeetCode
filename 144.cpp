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

class Problem144 {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return res;
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root){
        res.push_back(root->val);
        if (root->left) traverse(root->left);
        if (root->right) traverse(root->right);
    }
};