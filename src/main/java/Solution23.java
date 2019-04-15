public class Solution23 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode(int x) { val = x; }
     * }
     */
    public ListNode mergeKLists(ListNode[] lists) {
        double k = lists.length;
        if (k == 0) return null;
        while (k != 1) {
            int i;
            for (i = 0; i * 2 < k; i++) {
                if (i * 2 + 1 < k) lists[i] = merge(lists[i * 2], lists[i * 2 + 1]);
                else lists[i] = lists[i * 2];
            }
            k = Math.ceil(k / 2.0);
        }

        return lists[0];
    }

    public ListNode merge(ListNode first, ListNode sec) {
        if (first == null && sec == null) return null;
        if (first == null) return sec;
        if (sec == null) return first;
        ListNode head, p;
        if (first.val < sec.val) {
            head = first;
            first = first.next;
        } else {
            head = sec;
            sec = sec.next;
        }
        p = head;
        while (first != null && sec != null) {
            if (first.val < sec.val) {
                p.next = first;
                p = p.next;
                first = first.next;
            } else {
                p.next = sec;
                p = p.next;
                sec = sec.next;
            }
        }
        while (first != null) {
            p.next = first;
            p = p.next;
            first = first.next;
        }
        while (sec != null) {
            p.next = sec;
            p = p.next;
            sec = sec.next;
        }
        p.next = null;
        return head;
    }
}
