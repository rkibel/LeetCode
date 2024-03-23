struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {        
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast->next) slow = slow->next;
        
        ListNode* pre = nullptr;
        while (slow) {
            fast = slow->next;
            slow->next = pre;
            pre = slow;
            slow = fast;
        }
        slow = pre;

        while(head && slow) {
            fast = head->next;
            pre = slow->next;
            head->next = slow;
            slow->next = fast;
            head = fast;
            slow = pre;
        }
        if (head && head->next) head->next->next = nullptr;

    }
};