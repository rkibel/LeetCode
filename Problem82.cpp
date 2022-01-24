struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Problem82 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *curr = head->next;
        while(curr && head->val == curr->val) curr = curr->next;
        (curr == head->next) ? head->next = deleteDuplicates(curr) : head = deleteDuplicates(curr);
        return head;
    }
};