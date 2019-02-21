public class Solution70 {
    public int climbStairs(int n) {
        int x = 1;
        int num = 2;
        if (n == 1 || n == 2) return n;
        for (int i = 0; i < n - 2; i++) {
            num += x;
            x = num - x;
        }
        return num;
    }
}
