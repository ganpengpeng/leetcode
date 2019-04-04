public class Solution345 {
    public String reverseVowels(String s) {
        char[] sb = s.toCharArray();
        for (int i = 0, j = s.length() - 1; i < j; ) {
            while (i < j && !isVowel(sb[i])) {
                i += 1;
            }
            while (i < j && !isVowel(sb[j])) {
                j -= 1;
            }
            if (i < j) {
                char t = sb[j];
                sb[j] = sb[i];
                sb[i] = t;
                i += 1;
                j -= 1;
            }
        }
        return new String(sb);
    }

    public boolean isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
}
