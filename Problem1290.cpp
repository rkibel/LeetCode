
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem1290 {
public:
    int getDecimalValue(ListNode* head) {
        int c = 0;
        for (ListNode* i = head; i; i = i->next){
            c <<= 1;
            if (i->val == 1) c++;
        }
        return c;
    }
};