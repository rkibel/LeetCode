/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <algorithm> 
#include <queue>
using namespace std;
class Problem993 {
    struct TreeNode{
        int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int len = q.size();
            bool a = false, b = false;
            for (int i = 0; i < len; ++i){
                TreeNode* temp = q.front();
                q.pop();
                
                if (temp->val == x)
                    a = true;
                if (temp-> val == y)
                    b = true;
                
                if (temp->left && temp->right){
                    if ((temp->left->val == x && temp->right->val == y) 
                    || (temp->left->val == y && temp->right->val == x))
                        return false;
                }
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);    
                
            }
            if (a && b)
                return true;
        }
        return false;
    }
};