#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Problem160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> a;
        for (; headA; headA = headA->next) a.push_back(headA);
        for (; headB; headB = headB->next){
            if (find(a.begin(), a.end(), headB) != a.end()) return headB;
        }
        return nullptr;
    }
};