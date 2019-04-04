import java.util.ArrayList;

public class Solution809 {
    public static void main(String[] args) {
        String S = "heeellooo";
        String[] words = new String[]{"hello", "hi", "helo"};
        Solution809 solution809 = new Solution809();
        System.out.println(solution809.expressiveWords(S, words));
    }

    public int expressiveWords(String S, String[] words) {
        ArrayList<String> list1 = new ArrayList<>();
        int index = 0;
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i - 1) != S.charAt(i)) {
                list1.add(S.substring(index, i));
                index = i;
            }
        }
        list1.add(S.substring(index));
        int count = 0;
        for (String word : words) {
            if (judge(list1, word)) {
                count += 1;
            }
        }
        return count;
    }

    public boolean judge(ArrayList<String> list1, String word) {
        ArrayList<String> list2 = new ArrayList<>();
        int index = 0;
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i - 1) != word.charAt(i)) {
                list2.add(word.substring(index, i));
                index = i;
            }
        }
        list2.add(word.substring(index));
        if (list1.size() != list2.size())
            return false;
        for (int i = 0; i < list1.size(); ++i) {
            if ((list1.get(i).length() >= 3 && list1.get(i).length() > list2.get(i).length() ||
                 list1.get(i).length() == list2.get(i).length()) &&
                list1.get(i).charAt(0) == list2.get(i).charAt(0)) {

            } else return false;
        }
        return true;
    }
}
