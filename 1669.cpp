class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start, *end = list1;
        for (int i = 0; i <= b; ++i) {
            if (i == a-1) start = end;
            end = end->next;
        }
        start->next = list2;
        while(start->next) start = start->next;
        start->next = end;
        return list1;
    }
};