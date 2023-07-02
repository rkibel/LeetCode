
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
        ListNode *last = nullptr, *secondToLast;
        int len = 0;
        for (ListNode* temp = head; temp; temp = temp->next){
            len++;
            secondToLast = last;
            last = temp;
        }
        if (len < 3) return;
        secondToLast->next = nullptr;
        last->next = head->next;
        head->next = last;
        reorderList(head->next->next);
    }
};