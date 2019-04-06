public class Solution687 {
    int max = 0;

    public int longestUnivaluePath(TreeNode root) {
        if (root == null)
            return 0;
        int len = helper(root, root.val);
        if (root.left != null)
            len = Math.max(len, longestUnivaluePath(root.left));
        if (root.right != null)
            len = Math.max(len, longestUnivaluePath(root.right));
        max = Math.max(max, len);
        return max;
    }

    public int helper(TreeNode root, int v) {
        if (root == null || root.val != v)
            return -1;

        int l = helper(root.left, v);
        int r = helper(root.right, v);
        if (l + r + 2 > max)
            max = l + r + 2;
        return Math.max(l, r) + 1;
    }
}
