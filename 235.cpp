struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Problem235 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((p->val >= root->val && q->val <= root->val) || (p->val <= root->val && q->val >= root->val)) return root;
        return (q->val < root->val && p->val < root->val) ? lowestCommonAncestor(root->left, p, q) :             
                                                            lowestCommonAncestor(root->right, p, q);
    }
};