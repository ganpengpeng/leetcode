public class Solution28 {
    public static void main(String[] args) {
        Solution28 solution28 = new Solution28();
        solution28.strStr("hello", "ll");
    }

    public int strStr(String haystack, String needle) {
        int i = 0, j = 0;
        if(needle.length() == 0) return 0;
        if(haystack.length() < needle.length()) return -1;
        int[] next = getNext(needle);
        for(; i < haystack.length();){
            if(j == -1 || haystack.charAt(i) == needle.charAt(j)){
                i += 1;
                j += 1;
            } else {
                j = next[j];
            }
            if(j == needle.length()) return i - needle.length();
        }
        return -1;
    }

    private int[] getNext(String s){
        int[] next = new int[s.length()];
        next[0] = -1;
        int k = -1;
        for(int j = 0; j < s.length() - 1;){
            if(k == -1 || s.charAt(j) == s.charAt(k)){
                next[++j] = ++k;
            } else {
                k = next[k];
            }
        }
        return next;
    }
}
