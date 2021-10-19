/**
 * Definition for a binary tree node.
struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>

class Problem100 {
    struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue <TreeNode*> a;
        queue <TreeNode*> b;
        a.push(p);
        b.push(q);
        bool same = true;
        if (a.size() != b.size())
            same = false;
        else {
            while (!a.empty()) {
                TreeNode* x1 = a.front();
                a.pop();
                TreeNode* x2 = b.front();
                b.pop();
                if (x1->val != x2->val){
                    same = false;
                    break;
                }
            }   
        }
        return same;
    }
};