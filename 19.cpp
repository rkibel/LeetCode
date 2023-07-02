
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        for (ListNode* i = head; i; i = i->next) len++;
        len = len-n;
        if (len == 0) return head->next;
        ListNode* temp = head;
        for (int i = 0; i < len-1; i++) temp = temp->next;
        temp->next = (temp->next->next) ? temp->next->next : nullptr;
        return head;
    }
};