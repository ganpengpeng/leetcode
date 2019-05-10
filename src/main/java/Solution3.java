import java.util.Arrays;

public class Solution3 {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        int start = 0;
        int[] index = new int[256];

        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;
        Arrays.fill(index, -1);

        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (index[c] == -1) {
                index[c] = i;
            } else {
                //System.out.printf("%d\t%d\n",i,start);
                max = Math.max(max, i - start);
                //TODO: trick
                // 更新start到下一个未出现重复字符的最左位置
                start = index[c] + 1 > start ? index[c] + 1 : start;
                index[c] = i;
            }
        }
        return Math.max(max, s.length() - start);
    }
}
