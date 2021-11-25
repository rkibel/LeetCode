#include "vector"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* ans;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* curr = ans;
        while(!lists.empty()){
            curr = getMin(lists);
            curr = curr->next;        
        }
        return ans;
    }
    ListNode*& getMin(vector<ListNode*>& lists){
        ListNode*& minNode = lists[0];
        ListNode*& currNode = lists[0];
        for (int i = lists.size()-1; i >= 0; i--){
            if (lists[i] == nullptr) lists.erase(lists.begin() + i);
            currNode = lists[i];
            if (currNode->val < minNode->val)
                minNode = currNode;
        }
        ListNode*& m = minNode;
        m = m->next;
        return minNode;
    }
};