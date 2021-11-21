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
            TreeNode* output = new TreeNode(postorder[postorder.size()-1]);

            return output;
        }
};