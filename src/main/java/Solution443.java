public class Solution443 {
    public int compress(char[] chars) {
        int i = 0, j = 0;
        int index = 0;
        int len = chars.length;
        if (len == 1)
            return 1;
        for (; j < len; ) {
            int sum = 0;
            while (j < len && chars[i] == chars[j]) {
                sum += 1;
                j += 1;
            }
            if (sum != 1) {
                chars[index++] = chars[i];
                String s = String.valueOf(sum);
                for (int k = 0; k < s.length(); k++) {
                    chars[index++] = s.charAt(k);
                }
            } else {
                chars[index++] = chars[i];
            }
            i = j;
        }
        return index;
    }
}
