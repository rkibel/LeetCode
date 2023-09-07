struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* r = head;
        ListNode* l = (left > 1) ? head : nullptr;
        for (int i = 1; i < right; ++i){
            if (i < left-1) l = l->next;
            r = r->next;
        }

        for (int i = 0; i < right-left; i++) {
            ListNode* remover = l ? l->next : head;
            if (l) l->next = l->next->next;
            else head = head->next;
            remover->next = r->next;
            r->next = remover;
        }
        return head ? head : r;
    }
};