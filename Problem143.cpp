
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Problem143 {
public:
    void reorderList(ListNode* head) {
        ListNode* temp = head, *last = nullptr, *secondToLast;
        int len = 0;
        while(temp){
            len++;
            secondToLast = last;
            last = temp;
            temp = temp->next;
        }
        if (len < 3) return;
        ListNode* res = head->next;
        secondToLast->next = nullptr;
        head->next = last;
        last->next = res;
        reorderList(res);
    }
};