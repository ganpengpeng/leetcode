public class Solution142 {
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return null;
        ListNode fir = head;
        ListNode sec = head;
        int steps = 0;
        while (fir.next != null && fir.next.next != null) {
            fir = fir.next.next;
            sec = sec.next;
            if (fir == sec) {
                break;
            }
        }
        if (fir.next == null || fir.next.next == null) {
            return null;
        }
        sec = head;
        while (sec != fir) {
            fir = fir.next;
            sec = sec.next;
        }
        return fir;
    }
}