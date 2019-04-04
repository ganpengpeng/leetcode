public class Solution344 {
    public void reverseString(char[] s) {
        int i = 0;
        int j = s.length - 1;
        while (i< j){
            char t = s[j];
            s[j] = s[i];
            s[i] = t;
            i += 1;
            j -= 1;
        }
    }
}
