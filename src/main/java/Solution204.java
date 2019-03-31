import java.util.ArrayList;
import java.util.List;

public class Solution204 {
    public static void main(String[] args) {
        Solution204 solution204 = new Solution204();
        solution204.countPrimes(49979);
    }

    public int countPrimes(int n) {
        int count=0;
        if(n<=1)return 0;
        boolean[] flag = new boolean[n];

        for(int i=2;i<=(int)Math.sqrt(n);i++){
            if(!flag[i]){
                for(int j=i;j*i<n;j++){
                    flag[j*i]=true;
                }
            }
        }

        for(int i=2;i<n;i++)
            if(!flag[i])count++;

        return count;
    }
}
