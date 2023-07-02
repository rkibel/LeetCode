struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Problem234 {
public:
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        ListNode*a = head, *b = head;
        while(a){
            a = a->next, b = b->next;
            if (a) a = a->next;
        }
        ListNode* rev = reverseList(b);
        while(rev){
            if (rev->val != head->val) return false;
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
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