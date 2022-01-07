#include <stdlib.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem382 {
public:
    ListNode* node;
    int len;
    Problem382(ListNode* head) {
        node = head;
        len = 0;
        for (; head; head = head->next) len++;
    }
    int getRandom() {
        int r = rand() % len;
        ListNode* temp = node;
        for (int i = 0; i < r; i++) temp = temp->next;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */