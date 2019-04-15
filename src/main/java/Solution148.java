public class Solution148 {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        // TODO trick
        // we should think about divide and conquer
        // when question request a O(nlogn) time complexity
        ListNode fir = null, sec = head, thr = head;
        if (head.next.next == null){
            if (head.val <= head.next.val){
                return head;
            }else {
                ListNode p = head.next;
                head.next = p.next;
                p.next = head;
                return p;
            }
        }
        while (thr.next != null && thr.next.next != null) {
            fir = sec;
            sec = sec.next;
            thr = thr.next.next;
        }
        fir.next = null;
        ListNode l = sortList(head);
        ListNode r = sortList(sec);
        return merge(l, r);
    }

    public ListNode merge(ListNode l, ListNode r) {
        ListNode head = new ListNode(0), p = head;

        while (l != null && r != null) {
            if (l.val < r.val) {
                p.next = l;
                l = l.next;
                p = p.next;
            } else {
                p.next = r;
                p = p.next;
                r = r.next;
            }
        }
        while (l != null) {
            p.next = l;
            p = p.next;
            l = l.next;
        }
        while (r != null) {
            p.next = r;
            p = p.next;
            r = r.next;
        }
        return head.next;
    }
}
