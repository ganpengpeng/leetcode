import java.util.ArrayList;
import java.util.List;

public class Solution22 {
    List<String> list = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        StringBuilder sb = new StringBuilder();
        helper(sb, 0, 0, n);
        return list;
    }

    public void helper(StringBuilder sb, int a, int b, int n) {
        if (sb.length() == n * 2) {
            list.add(sb.toString());
            return;
        }
        if (a > b) {
            sb.append(')');
            helper(sb, a, b + 1, n);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (a < n) {
            sb.append('(');
            helper(sb, a + 1, b, n);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
