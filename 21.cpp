struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Problem21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1->val < list2->val){
            ListNode* temp = list1->next;
            list1->next = mergeTwoLists(temp, list2);
            return list1;
        }
        else{
            ListNode* temp = list2->next;
            list2->next = mergeTwoLists(list1, temp);
            return list2;
        }
    }
};