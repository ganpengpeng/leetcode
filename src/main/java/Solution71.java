import java.util.ArrayList;
import java.util.List;

public class Solution71 {
    public String simplifyPath(String path) {
        List<String> result = new ArrayList<String>();
        String[] pieces = path.split("/");
        for (int i = 0; i < pieces.length; i++) {
            if (pieces[i].equals(".") || pieces[i].length() == 0){
                continue;
            }else if (pieces[i].equals("..")){
                if (!result.isEmpty()){
                    result.remove(result.size()-1);
                }
            }else {
                result.add(pieces[i]);
            }
        }
        String r = "";
        for (String s : result) {
            r += "/" + s;
        }
        if (r.equals("")){
            return "/";
        }
        return r;
    }
    public static void main(String[] args){
        String path = "/a//b////c/d//././/..";
        System.out.println();
        Solution71 solution71 = new Solution71();
        System.out.println(solution71.simplifyPath(path));
    }
}
