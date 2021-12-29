#include <queue>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};
class Problem116 {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        int counter = 2;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if ((counter & counter-1) != 0) node->next = q.front();
            if (node->left){
                q.push(node->left);
                q.push(node->right);
            }
            counter++;
        }
        return root;
    }
};