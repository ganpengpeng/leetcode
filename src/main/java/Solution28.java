public class Solution28 {
    public static void main(String[] args) {
        Solution28 solution28 = new Solution28();
        solution28.strStr("hello", "ll");
    }

    public int strStr(String haystack, String needle) {
        if (needle.length() == 0)
            return 0;
        int[] next = getNext(needle);
        int i = 0, j = 0;
        for (; i < haystack.length() && j < needle.length(); ) {
            if (j == -1 || haystack.charAt(i) == needle.charAt(j)) {
                i += 1;
                j += 1;
            } else {
                j = next[j];
            }
        }
        if (j == needle.length()) {
            return i - needle.length();
        }
        return -1;
    }

    public int[] getNext(String p) {
        int[] next = new int[p.length()];
        int k = -1, j = 0;

        next[0] = -1;
        while (j < p.length() - 1) {
            if (k == -1 || p.charAt(j) == p.charAt(k)) {
                next[++j] = ++k;
            } else {
                k = next[k];
            }
        }
        return next;
    }
}
