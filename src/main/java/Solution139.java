import java.util.List;

public class Solution139 {
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s == null || s.length() == 0)
            return true;
        for (int i = 0; i < wordDict.size(); i++) {
            int index = s.indexOf(wordDict.get(i));
            if (index != -1) {
                String l = s.substring(0, index);
                String r = s.substring(index + wordDict.get(i).length());
                if (wordBreak(l, wordDict) && wordBreak(r, wordDict))
                    return true;
            }
        }
        return false;
    }
}
