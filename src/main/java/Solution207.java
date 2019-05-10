import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class Solution207 {
    public static void main(String[] args) {
        int[][] prerequisites = {{1, 0}};
        Solution207 solution207 = new Solution207();
        solution207.canFinish(2, prerequisites);
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ConcurrentHashMap<Integer, Integer> indegree = new ConcurrentHashMap<>();
        HashMap<Integer, HashSet<Integer>> outEdge = new HashMap<>();

        for (int i = 0; i < prerequisites.length; ++i) {
            if (indegree.containsKey(prerequisites[i][0])){
                indegree.computeIfPresent(prerequisites[i][0], (k, v) -> v + 1);
            } else {
                indegree.putIfAbsent(prerequisites[i][0], 1);
            }
            if (!indegree.containsKey(prerequisites[i][1])){
                indegree.put(prerequisites[i][1], 0);
            }
            if (outEdge.containsKey(prerequisites[i][1])) {
                outEdge.get(prerequisites[i][1]).add(prerequisites[i][0]);
            } else {
                HashSet<Integer> set = new HashSet<>();
                set.add(prerequisites[i][0]);
                outEdge.put(prerequisites[i][1], set);
            }
        }
        while (!indegree.isEmpty()) {
            boolean flag = true;
            for (Map.Entry<Integer, Integer> entry : indegree.entrySet()) {
                if (entry.getValue() == 0) {
                    flag = false;
                    HashSet<Integer> set = outEdge.get(entry.getKey());
                    indegree.remove(entry.getKey());
                    if (set == null) continue;
                    for (Integer course : set) {
                        indegree.computeIfPresent(course, (k, v) -> v - 1);
                    }
                }
            }
            if (flag)
                return false;
        }
        return true;
    }
}
