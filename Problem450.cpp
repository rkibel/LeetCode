struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Problem450 {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* found = findTree(root, key);
        if (!found)
            return nullptr;
        TreeNode* replacer = traverseTree(found);
        found->val = replacer->val;
        return root;
    }
    TreeNode* traverseTree(TreeNode*& curr){
        TreeNode* output = nullptr;
        if (curr->left){
            TreeNode* result = traverseTree(curr->left);
            (result != nullptr) ? output = result : output = nullptr;
        }
        else if (curr->right){
            TreeNode* result = traverseTree(curr->right);
            (result != nullptr) ? output = result : output = nullptr;
        }
        else{ 
            output = curr;
            curr = nullptr;
        }
        return output;
    }
    TreeNode* findTree(TreeNode* tree, int key){
        TreeNode* output = nullptr;
        if (tree->val == key)
            output = tree;
        else if (tree->left)
            output = findTree(tree->left, key) != nullptr ? findTree(tree->left, key) : nullptr;
        else if (tree->right)
            output = findTree(tree->right, key) != nullptr ? findTree(tree->right, key) : nullptr;
        return output;
    }
};