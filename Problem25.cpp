
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem25 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int counter = 0;
        bool enough = false;
        for (ListNode* temp = head; temp; temp = temp->next){
            counter++;
            if (counter >= k){
                enough = true;
                break;
            }
        }
        if (!enough) return head;
        ListNode* tail = head;
        for (int i = 0; i < k-1; i++){
            ListNode* temp = tail->next;
            tail->next = tail->next->next;
            temp->next = head;
            head = temp;
        }
        tail->next = reverseKGroup(tail->next, k);
        return head;
    }
};