public class Solution206 {
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;
        ListNode newHead = new ListNode(0);
        ListNode p;
        newHead.next = null;
        while(head != null){
            p = newHead.next;
            newHead.next = head;
            head = head.next;
            newHead.next.next = p;
        }
        return newHead.next;
    }
}
