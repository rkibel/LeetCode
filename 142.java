import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
public class Problem142 {
    public ListNode detectCycle(ListNode head) {
        List<ListNode> nodes = new ArrayList<>();
        for (; head != null; head = head.next){
            if (nodes.contains(head)) return head;
            nodes.add(head);
        }
        return null;
    }
}