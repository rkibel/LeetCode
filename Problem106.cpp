#include "vector"
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

class Problem106{
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
            post = postorder;
            in = inorder;
            curr = inorder.size()-1;
            return recursive(0, postorder.size()-1);
        }
        TreeNode* recursive(int left, int right){
            if (left > right)
                return NULL;
            
            int i = 0;
            while(in[i] != post[curr])
                i++;
            
            curr--;
            TreeNode* node = new TreeNode(in[i]);
            node->right = recursive(i+1, right);
            node->left = recursive(left, i-1);
            return node;
        }
    private:
        int curr;
        vector<int> post, in;
};