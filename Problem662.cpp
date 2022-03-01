#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Problem662 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        int res = 1;
        while(!q.empty()){
            int start = q.front().second, end = q.back().second;
            res = max(res, end-start+1);
            
            int count = q.size();
            for (int i = 0; i < count; i++){
                pair<TreeNode*, int> p = q.front();
                int index = p.second-start;
                q.pop();
                if (p.first->left) q.push({p.first->left, (long long)2*index+1});
                if (p.first->right) q.push({p.first->right, (long long)2*index+2});
            }
        }
        return res;
    }
};