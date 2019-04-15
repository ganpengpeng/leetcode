import java.util.HashMap;
import java.util.HashSet;

public class Solution207 {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        HashMap<Integer, HashSet<Integer>> inEdge = new HashMap<>();
        HashMap<Integer, HashSet<Integer>> outEdge = new HashMap<>();
        for (int i = 0; i < prerequisites.length; ++i) {
            if (inEdge.containsKey(prerequisites[i][0])) {
                inEdge.get(prerequisites[i][0]).add(prerequisites[i][1]);
            } else {
                HashSet<Integer> set = new HashSet<>();
                set.add(prerequisites[i][1]);
                inEdge.put(prerequisites[i][0], set);
            }
            if (outEdge.containsKey(prerequisites[i][1])) {
                outEdge.get(prerequisites[i][1]).add(prerequisites[i][0]);
            } else {
                HashSet<Integer> set = new HashSet<>();
                set.add(prerequisites[i][0]);
                outEdge.put(prerequisites[i][1], set);
            }
        }

    }

    public int helper(HashMap<Integer, HashSet<Integer>> inEdge, HashMap<Integer, HashSet<Integer>> outEdge) {
        for ()
    }
}
