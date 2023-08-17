struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode* small = head;
        if (head->val >= x) small = nullptr;
        while (small && small->next && small->next->val < x) small = small->next;
        ListNode* temp = (small) ? small->next : head;
        while (temp && temp -> next) {
            if (temp->next->val < x) {
                ListNode* n = temp->next;
                temp->next = n->next;
                n->next = (small) ? small->next : head;
                if (small) small->next = n;
                else head = n;
                small = n;
            }
            else temp = temp->next;
        }
        return head;
    }
};