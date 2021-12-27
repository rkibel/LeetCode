struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = head;
        for (ListNode* temp = head->next; temp; temp = temp->next)
            (temp->val == prev->val) ? prev->next = temp->next : prev = temp;
        return head;
    }
};