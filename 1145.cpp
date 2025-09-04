#include "common.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  int left_count = 0, right_count = 0;

  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    count(root, x);
    int rest = n - (left_count + right_count + 1);
    int max_cnt = std::max(rest, std::max(left_count, right_count));
    return max_cnt > n / 2;
  }

  int count(TreeNode* node, int x) {
    if (!node) return 0;
    int l = count(node->left, x);
    int r = count(node->right, x);
    if (node->val == x) {
      left_count = l;
      right_count = r;
    }
    return l + r + 1;
  }
};

int main() {
  Solution s;
  auto left = TreeNode(2, new TreeNode(4), new TreeNode(5));
  auto right = TreeNode(5);
  TreeNode root{1, &left, &right};
  cout << s.btreeGameWinningMove(&root, 5, 2) << endl;
}
