public class Solution98 {
    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        if (root.left != null && !isValidBST(root.left))
            return false;
        if (root.right != null && !isValidBST(root.right))
            return false;
        if (root.left != null) {
            TreeNode less = root.left;
            while (less.right != null)
                less = less.right;
            if (root.val <= less.val)
                return false;
        }
        if (root.right != null) {
            TreeNode gat = root.right;
            while (gat.left != null) {
                gat = gat.left;
            }
            if (root.val >= gat.val)
                return false;
        }
        return true;
    }
}
