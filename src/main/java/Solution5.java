public class Solution5 {
    public static void main(String[] args) {
        Solution5 solution5 = new Solution5();
        System.out.println(solution5.longestPalindrome("cbba"));
    }

    public String longestPalindrome(String s) {
        if (s.length() <= 1) return s;
        int mx = 0, id = 0;
        int rstPos = 0, rstLen = 0;
        StringBuilder sb = new StringBuilder("$#");
        for (int i = 0; i < s.length(); ++i) {
            sb.append(s.charAt(i));
            sb.append('#');
        }
        int[] p = new int[sb.length()];
        for (int i = 1; i < sb.length(); ++i) {
            // TODO: trick, key point here.
            p[i] = mx > i ? Math.min(p[id * 2 - i], mx - i) : 1;
            while ((i - p[i] >= 0) && (i + p[i] < sb.length()) && sb.charAt(i - p[i]) == sb.charAt(i + p[i])) {
                p[i] += 1;
            }
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            if (rstLen < p[i]) {
                rstLen = p[i];
                rstPos = i;
            }
        }
        System.out.println(rstPos + "\t" + rstLen);
        return s.substring((rstPos - rstLen) / 2, (rstPos - rstLen) / 2 + rstLen - 1);
    }
}
