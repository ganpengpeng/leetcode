import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution102 {

    public static void main(String[] args){
        Solution102 solution102 = new Solution102();
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        solution102.levelOrder(root);
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null)
            return new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        TreeNode end = root;
        queue.add(root);
        while (!queue.isEmpty()) {
            List<Integer> row = new ArrayList<>();
            TreeNode first;
            while (queue.getFirst() != end) {
                first = queue.getFirst();
                row.add(first.val);
                if (first.left != null)
                    queue.addLast(first.left);
                if (first.right != null)
                    queue.addLast(first.right);
                queue.removeFirst();
            }
            first = queue.getFirst();
            row.add(first.val);
            if (first.left != null)
                queue.addLast(first.left);
            if (first.right != null)
                queue.addLast(first.right);
            queue.removeFirst();
            end = queue.isEmpty() ? null : queue.getLast();
            result.add(row);
        }
        return result;
    }
}
