#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Problem141 {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> vec;
        for (; head && head->next; head = head->next){
            if (find(vec.begin(),  vec.end(), head->next) != vec.end()) return true;
            vec.push_back(head);
        }
        return false;
    }
};