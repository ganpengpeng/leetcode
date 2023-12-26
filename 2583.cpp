#include "common.h"

using namespace std;

class Solution {
 public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    std::priority_queue<uint64_t> rst;
    std::queue<TreeNode*> cur;
    cur.push(root);
    uint64_t sum = 0;
    std::queue<TreeNode*> temp;
    while (!cur.empty()) {
      TreeNode* node = cur.front();
      cur.pop();
      if (node->left) {
        temp.push(node->left);
      }
      if (node->right) {
        temp.push(node->right);
      }
      sum += node->val;
      if (cur.empty()) {
        rst.push(sum);
        cur.swap(temp);
        sum = 0;
      }
    }
    if (k > rst.size()) {
      return -1;
    }
    for (int i = 1; i < k; ++i) {
      rst.pop();
    }
    return rst.top();
  }
};

int main() {
  Solution s;
  TreeNode root(5, new TreeNode(8, new TreeNode(2, new TreeNode(4), new TreeNode(6)), new TreeNode(1)),
                new TreeNode(9, new TreeNode(3), new TreeNode(7)));
  cout << s.kthLargestLevelSum(&root, 2) << endl;
  return 0;
}