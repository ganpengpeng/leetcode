public class Solution434 {
    public int countSegments(String s) {
        int count = 0;
        int i = 0;
        if (s.length() == 0)
            return 0;
        while (i < s.length() && (s.charAt(i) == ' ' || s.charAt(i) == '\t'))
            i += 1;
        for (; i < s.length(); i++) {
            if (s.charAt(i) == ' ' || s.charAt(i) == '\t') {
                count += 1;
                while (i < s.length() && (s.charAt(i) == ' ' || s.charAt(i) == '\t'))
                    i += 1;
            }
        }
        if (s.charAt(s.length()-1) == ' ' || s.charAt(s.length()-1) == '\t')
            return count;
        return count += 1;
    }
}
