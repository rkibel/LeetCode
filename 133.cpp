#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Problem133 {
public:
    vector<Node*>vec = vector<Node*>(101, nullptr);
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (vec[node->val]) return vec[node->val];
        Node* clone = new Node(node->val, node->neighbors);
        vec[node->val] = clone;
        for (int i = 0; i < node->neighbors.size(); i++){
            clone->neighbors[i] = cloneGraph(node->neighbors[i]);   
        }
        return clone;
    }
};