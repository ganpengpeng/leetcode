import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution17 {
    public static void main(String[] args) {
        Solution17 solution17 = new Solution17();
        solution17.letterCombinations("23");
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return new ArrayList<String>();
        Map<Integer, String> map = new HashMap<Integer, String>();
        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");
        List<String> rst = new ArrayList<>();
        List<String> tmp = new ArrayList<>();
        rst.add("");
        for (int i = 0; i < digits.length(); ++i) {
            String s = map.get(digits.charAt(i) - '0');
            for (int j = 0; j < rst.size(); ++j)
                for (int k = 0; k < s.length(); ++k) {
                    tmp.add(rst.get(j) + s.charAt(k));
                }
            List<String> t = rst;
            rst = tmp;
            tmp = t;
            tmp.clear();
        }
        return rst;
    }
}
