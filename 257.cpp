#include <vector>
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
 
class Problem257 {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return res;
        traverse(root, to_string(root->val));
        return res;
    }
    void traverse(TreeNode* root, string curr){
        if (!root->left && !root->right) res.push_back(curr);
        if (root->left) traverse(root->left, curr + "->" + to_string(root->left->val));
        if (root->right) traverse(root->right, curr + "->" + to_string(root->right->val));
    }
};