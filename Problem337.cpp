#include <vector>
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
 
class Problem337 {
public:
    int rob(TreeNode* root) {
        vector<int> ans = r(root);
        return max(ans[0], ans[1]);
    }
    vector<int> r(TreeNode* root){
        if (!root) return vector<int>{0, 0};
        vector<int>left = r(root->left);
        vector<int>right = r(root->right);
        
        vector<int> ans;
        ans.push_back(max(left[0], left[1]) + max(right[0], right[1]));
        ans.push_back(root->val + left[0] + right[0]);
        return ans;
    }
};