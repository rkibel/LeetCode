
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Problem237 {
public:
    void deleteNode(ListNode* node) {
        for (; node && node->next; node = node->next){
            node->val = node->next->val;
            if (!node->next->next) node->next = nullptr;
        }
    }
};