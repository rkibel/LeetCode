
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Problem206 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* tail = head, *prev = head->next;
        tail->next = nullptr;
        if (!prev) return tail;
        for (ListNode* temp = prev->next; temp; temp = temp->next)
            prev->next = tail, tail = prev, prev = temp;
        prev->next = tail;
        return prev;
    }
};