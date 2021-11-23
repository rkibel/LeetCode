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
        TreeNode** result = findTree(root, key);
        //case 1: there is no node with key
        if (!result)
            return root;
        //case 2: the node with key has no children

        //case 3: the node with key has only right children

        //case 4: the node with key has only left children

        //case 5: the node with key has both children
        
    }
    TreeNode** findTree(TreeNode* tree, int key){
        if (tree){
            if (tree->val == key)
                return &tree;
            else if (tree->left && findTree(tree->left, key) != nullptr)
                return findTree(tree->left, key);
            else if (tree->right && findTree(tree->right, key) != nullptr)
                return findTree(tree->right, key);
        }
        return nullptr;
    }
};