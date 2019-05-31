import java.util.Arrays;
import java.util.LinkedList;

public class Solution56 {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        if (intervals.length <= 1) return intervals;
        LinkedList<int[]> rst = new LinkedList<>();
        int[] cur = intervals[0];
        for (int i = 0; i < intervals.length; ++i) {
            if (i + 1 < intervals.length) {
                int[] t2 = intervals[i + 1];
                if (t2[0] <= cur[1]) {
                    cur[1] = Math.max(cur[1], t2[1]);
                } else {
                    rst.add(cur);
                    cur = intervals[i + 1];
                }
            }
        }
        rst.add(cur);
        return rst.toArray(new int[0][0]);
    }
}
