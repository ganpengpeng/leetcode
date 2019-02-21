class Solution10 {
    Boolean[][] dp;

    public static void main(String[] args) {
        String s = "aaa";
        String p = "a*a";
        Solution10 solution10 = new Solution10();
        System.out.println(solution10.isMatch(s, p));
    }

    public boolean isMatch(String s, String p) {
        dp = new Boolean[s.length() + 1][p.length() + 1];
        for (int i = 0; i < s.length(); i++) {
            dp[i][p.length()] = false;
        }
        dp[s.length()][p.length()] = true;
        return judge(0, 0, s, p);
    }

    public boolean judge(int i, int j, String s, String p) {
        if (dp[i][j] != null) {
            return dp[i][j];
        }
        if (j == p.length()) {
            dp[i][j] = i == s.length();
            return dp[i][j];
        }
        boolean first = i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            dp[i][j] = first && judge(i + 1, j, s, p)
                       || judge(i, j + 2, s, p);
        } else {
            dp[i][j] = first && judge(i + 1, j + 1, s, p);
        }
        return dp[i][j];
    }
}