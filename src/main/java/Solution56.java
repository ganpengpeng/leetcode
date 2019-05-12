import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;

public class Solution56 {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        LinkedList<int[]> rst = new LinkedList<>();
        for(int i = 0; i < intervals.length; ++i){

        }
        return new int[1][1];
    }
}
