
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
        
        ListNode *mid = head;
        for (ListNode* temp = head; temp && temp->next; temp = temp->next->next) mid = mid->next;
        return mid;

        /*int len = 0, marker = 0;
        for (ListNode* temp = head; temp; temp = temp->next) len++;
        for (ListNode* temp = head; temp; temp = temp->next){
            if (marker == len/2) return temp;
            marker++;
        }
        return head;
        */
    }
};