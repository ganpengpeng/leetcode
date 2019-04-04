public class Solutin91 {
    public int numDecodings(String s) {
        if (s.length() == 1) {
            if (s.equals("0"))
                return 0;
            return 1;
        }
        if (s.length() == 2) {
            if (s.charAt(0) > '2' || s.charAt(0) == '2' && s.charAt(1) > '6' || s.charAt(1) == '0')
                return 1;
            return 2;
        }
        if (s.charAt(0) > '2' || s.charAt(0) == '2' && s.charAt(1) > '6' || s.charAt(1) == '0')
            return numDecodings(s.substring(1));
        return numDecodings(s.substring(1)) + numDecodings(s.substring(2));
    }
}
