
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem101 {
public:
    bool isSymmetric(TreeNode* root) {
        return symmetric(root->left, root->right);
    }
    bool symmetric(TreeNode*a, TreeNode*b){
        if (!a && !b) return true;
        if ((a && !b) || (b && !a) || (a->val != b->val)) return false;
        return symmetric(a->right, b->left) && symmetric(a->left, b->right);
    }
};