import java.util.List;

public class Solution120 {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] result = new int[n];
        List<Integer> lastRow = triangle.get(n - 1);
        for (int i = 0; i < lastRow.size(); i++) {
            result[i] = lastRow.get(i);
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                result[j] = Math.min(result[j], result[j + 1]) + triangle.get(i).get(j);
            }
        }
        return result[0];
    }
}
