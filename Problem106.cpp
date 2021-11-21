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
        void addNodes(TreeNode* treenode, vector<int>& inorder, vector<int>& postorder){
            if (!treenode->val)
                return;
            int v = treenode->val;
            int inIndex = findVal(inorder, v);
            int postIndex = findVal(postorder, v);
            if (inIndex == 0){
                inorder.erase(inorder.begin() + inIndex);
                postorder.erase(postorder.begin() + postIndex);
                addNodes(treenode->right, inorder, postorder);
                return;
            }
            if (inIndex == inorder.size() - 1){
                inorder.erase(inorder.begin() + inIndex);
                postorder.erase(postorder.begin() + postIndex);
                addNodes(treenode->left, inorder, postorder);
                return;
            }
            //find lVal
            int lMin = INT_MAX;
            int lVal = NULL;
            for (unsigned int i = 0; i < inIndex; i++){
                int deter = inorder[i];
                int deterIndex = findVal(postorder, deter);
                int lDist = abs(postIndex - deterIndex);
                if (lDist < lMin){
                    lMin = lDist;
                    lVal = deter;
                }
            }
            inorder.erase(inorder.begin() + findVal(inorder, lVal));
            postorder.erase(postorder.begin() + findVal(postorder, lVal));
            treenode->left->val = lVal;
            addNodes(treenode->left, inorder, postorder);
            //find rVal
            int rMin = INT_MAX;
            int rVal = NULL;
            for (unsigned int i = inIndex + 1; i < inorder.size(); i++){
                int deter = inorder[i];
                int deterIndex = findVal(postorder, deter);
                int rDist = abs(postIndex - deterIndex);
                if (rDist < rMin){
                    rMin = rDist;
                    rVal = deter;
                }
            }
            inorder.erase(inorder.begin() + findVal(inorder, rVal));
            postorder.erase(postorder.begin() + findVal(postorder, rVal));
            treenode->right->val = rVal;
            addNodes(treenode->right, inorder, postorder);

        }
        int findVal(vector<int> x, int val){
            return find(x.begin(), x.end(), val) - x.begin();
        }
};