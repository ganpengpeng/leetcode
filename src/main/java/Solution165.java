public class Solution165 {
    public static void main(String[] args){
        Solution165 solution165 = new Solution165();
        solution165.compareVersion("1.1", "1.0");
    }
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int l1 = v1.length;
        int l2 = v2.length;
        for (int i = 0, j = 0; i < l1 || j < l2;) {
            int x = i < l1 ? Integer.valueOf(v1[i]) : 0;
            int y = j < l2 ? Integer.valueOf(v2[j]) : 0;
            if (x > y)
                return 1;
            if (x < y)
                return -1;
            i += 1;
            j += 1;
        }
        return 0;
    }
}
