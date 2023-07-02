#include <iostream>
using namespace std;

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
        TreeNode* iter = root, *par = nullptr;
        while(iter && iter->val != key){
            par = iter;
            if (iter->val < key) iter = iter->right;
            else iter = iter->left;
        }
        if (!iter) return root;

        if (!iter->left || !iter->right){
            auto child = iter->left ? iter->left : iter->right;
            if (!par) root = child;
            else if (par->left == iter) par->left = child;
            else par->right = child;
        }
        else{
            auto curr = iter;
            par = iter, iter = iter->right;
            while(iter->left) par = iter, iter = iter->left;
            curr->val = iter->val;

            if (par->left == iter) par->left = iter->right;
            else par->right = iter->right;
        }
        delete iter;
        return root;
    }
};