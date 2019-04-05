import java.util.*;
import java.util.function.BiFunction;

public class Solution387 {
    public int firstUniqChar(String s) {
        Map<Character, Integer> map = new LinkedHashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            map.computeIfPresent(s.charAt(i), (k, v) -> v + 1);
            map.computeIfAbsent(s.charAt(i), k-> 1);
        }
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1)
                return s.indexOf(entry.getKey());
        }
        return -1;
    }
}
