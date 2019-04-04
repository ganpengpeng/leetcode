public class Solution58 {
    public int lengthOfLastWord(String s) {
        if (s.length() == 0)
            return 0;
        char[] chars = s.toCharArray();
        int len = chars.length;
        int i = 0;
        int result = 0;
        while (i < len && chars[i] == ' ') {
            // skip leading space
            i += 1;
        }
        for (int j = i; j < len; j++) {
            if (chars[j] == ' ') {
                result = j - i;
                while (j < len && chars[j] == ' ') {
                    // skip space between two words
                    j += 1;
                }
                i = j;
            }
        }
        if (i == 0)
            // case: total space
            return len;
        if (chars[len - 1] != ' ')
            // case: last word at end
            return len - i;
        return result;
    }
}
