
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Problem876 {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0, marker = 0;
        for (ListNode* temp = head; temp; temp = temp->next) len++;
        len = len/2 + 1;
        for (ListNode* temp = head; temp; temp = temp->next){
            marker++;
            if (marker == len) return temp;
        }
        return head;
    }
};