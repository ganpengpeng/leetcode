public class Solution279 {
    public int numSquares(int n) {
        int[] a = new int[n + 1];
        int sn = (int) Math.sqrt(n);

        for (int i = 1; i <= sn; i++) {
            a[i * i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 1; j <= (int) Math.sqrt(i); j++) {
                if (min > a[i - j * j] + 1) {
                    min = a[i - j * j] + 1;
                }
            }
            a[i] = min;
        }
        return a[n];
    }
}
