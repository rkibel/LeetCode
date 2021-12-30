
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem147 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* prev = head;
        for (ListNode* temp = head->next; temp; temp = temp->next){
            if (temp->val < prev->val){
                prev->next = temp->next;
                ListNode* pre = nullptr;
                for (ListNode* iter = head; iter && iter->val < temp->val; iter = iter->next) pre = iter;
                if (pre) temp->next = pre->next, pre->next = temp;
                else temp->next = head, head = temp;
            }
            prev = temp;
        }
        return head;
    }
};