public class Solution43 {
    public String multiply(String num1, String num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        int[] pos = new int[n1 + n2];
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int x = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + pos[i + j + 1];
                pos[i + j] += x / 10;
                pos[i + j + 1] = x % 10;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < pos.length; i++) {
            if (!(pos[i] == 0 && sb.length() == 0))
                sb.append(pos[i]);
        }
        if (sb.length() == 0)
            return "0";
        return sb.toString();
    }
//    public String multi(String num1, String num2){
//        int l1 = num1.length();
//        int l2 = num2.length();
//        int l = Math.min(l1, l2) / 2;
//        String a = num1.substring(0, l);
//        String b = num1.substring(l);
//        String c = num2.substring(0, l);
//        String d = num2.substring(l);
//    }
}
