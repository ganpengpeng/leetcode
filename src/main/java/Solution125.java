public class Solution125 {
    public static void main(String[] args) {
        String s = "A man, a plan, a canal: Panama";
        Solution125 solution125 = new Solution125();
        solution125.isPalindrome(s);
    }

    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        if (s.length() == 0)
            return true;
        for (; i < j; ) {
            while (i < j && !charValid(s.charAt(i)))
                i += 1;
            while (i < j && !charValid(s.charAt(j)))
                j -= 1;
            if (toLower(s.charAt(i)) != toLower(s.charAt(j))) {
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }

    public boolean charValid(char c) {
        if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            return true;
        return false;
    }

    public char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return (char) ('a' + c - 'A');
        return c;
    }
}
