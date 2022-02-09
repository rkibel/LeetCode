
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
        //iterative approach
        ListNode* temp = head, *next = nullptr, *prev = nullptr;
        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
        
        //recursive approach
        /*if (!head || !head->next) return head;
        ListNode* newNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newNode;
        */
    }
};