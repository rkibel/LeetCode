#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct compare
{
    bool operator()(const ListNode* a, const ListNode* b){ 
        return a->val < b->val; 
    }
};
class Problem148 {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (ListNode* temp = head; temp; temp = temp->next) q.push(temp);
        ListNode* builder = nullptr;
        while(!q.empty()){
            ListNode* temp = q.top();
            temp->next = builder;
            builder = temp;
            q.pop();
        }
        return builder;
    }
};