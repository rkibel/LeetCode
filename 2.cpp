
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* iter = new ListNode, *output = iter;
        int remainder = 0;
        while(l1 || l2){
            int v;
            if (l2 && l1) v = l2->val + l1->val + remainder;
            else if (!l1) v = l2->val + remainder;
            else v = l1->val + remainder;
            remainder = 0;
            if (v >= 10){
                remainder = v/10;
                v %= 10;
            }            
            iter->val = v;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            if (l1 || l2){
                iter->next = new ListNode;
                iter = iter->next;
            }
        }
        if (remainder != 0) iter->next = new ListNode(remainder);
        return output;
    }
};