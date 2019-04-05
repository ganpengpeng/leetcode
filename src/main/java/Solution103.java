import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution103 {
    public static void main(String[] args) {
        Solution103 solution103 = new Solution103();
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        solution103.zigzagLevelOrder(root);
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        boolean flag = false;
        if (root == null)
            return result;
        queue.add(root);
        while (!queue.isEmpty()) {
            LinkedList<Integer> row = new LinkedList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode first = queue.getFirst();
                queue.removeFirst();
                if (flag)
                    row.add(first.val);
                else
                    row.addFirst(first.val);
                if (first.left != null)
                    queue.addLast(first.left);
                if (first.right != null)
                    queue.addLast(first.right);
            }
            flag = !flag;
            result.add(row);
        }
        return result;
    }
}
