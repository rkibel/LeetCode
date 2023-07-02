#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minNode = getMinNode(lists);
        if (minNode == -1) return nullptr;
        ListNode* merged = lists[minNode], *head = merged;
        lists[minNode] = lists[minNode]->next;
        minNode = getMinNode(lists);
        while(minNode != -1){
            merged->next = lists[minNode];
            merged = merged->next;
            lists[minNode] = lists[minNode]->next;
            minNode = getMinNode(lists);
        }
        return head;
    }
    int getMinNode(vector<ListNode*> nodes){
        int min = -1;
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i] && (min == -1 || nodes[i]->val < nodes[min]->val)) min = i;
        return min;
    }
};