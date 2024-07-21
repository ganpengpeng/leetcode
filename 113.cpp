#include "common.h"

using namespace std;

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
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return rst;
    }

    vector<int> v;
    dfs(root, targetSum, v);
    return rst;
  }

  void dfs(TreeNode* node, int target_num, vector<int>& v) {
    if (node->left == nullptr && node->right == nullptr) {
      if (target_num == node->val) {
        v.push_back(node->val);
        rst.push_back(v);
        v.pop_back();
      }
      return;
    }
    v.push_back(node->val);
    if (node->left) {
      dfs(node->left, target_num - node->val, v);
    }
    if (node->right) {
      dfs(node->right, target_num - node->val, v);
    }

    v.pop_back();
  }
  vector<vector<int>> rst;
};

int main() {
  Solution s;
  vector<vector<int>> v = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  return 0;
}
