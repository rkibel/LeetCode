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
class Problem112 {
    private:
        vector<int>sums;
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            setSums(root, 0);
            return find(sums.begin(), sums.end(), targetSum) != sums.end();
        }
        
        void setSums(TreeNode* node, int sum){
            if (!node)
                return;
            int v = node->val;
            if (!node->left && !node->right)
                sums.push_back(sum + v);
            if (node->left)
                setSums(node->left, sum + v);
            if (node->right)
                setSums(node->right, sum + v);
        }
};