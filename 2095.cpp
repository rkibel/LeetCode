struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int counter = 0;
        for (ListNode* temp = head; temp; temp = temp->next) counter++;
        int x = counter / 2;
        if (x == 0) return head->next;
        ListNode* temp = head;
        for (int i = 1; i < x; i++) temp = temp->next;
        temp->next = temp->next->next;
        return head;
    }
};