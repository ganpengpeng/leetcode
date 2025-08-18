#include "common.h"

class Solution {
 public:
  vector<int> diffWaysToCompute(string exp) { return func(exp, 0, exp.size() - 1); }
  vector<int> func(string exp, int s, int e) {
    auto iter = dp.find({s, e});
    if (iter != dp.end()) {
      return iter->second;
    }
    vector<int> rst;
    bool is_num = true;
    for (auto i = s; i <= e; ++i) {
      vector<int> left, right;
      if (!isdigit(exp[i])) {
        left = func(exp, s, i - 1);
        right = func(exp, i + 1, e);
        is_num = false;
      }
      if (exp[i] == '+') {
        for (const auto& l : left) {
          for (const auto& r : right) {
            rst.push_back(l + r);
          }
        }
      }
      if (exp[i] == '-') {
        for (const auto& l : left) {
          for (const auto& r : right) {
            rst.push_back(l - r);
          }
        }
      }
      if (exp[i] == '*') {
        for (const auto& l : left) {
          for (const auto& r : right) {
            rst.push_back(l * r);
          }
        }
      }
    }
    if (is_num) {
      rst.push_back(atoi(exp.substr(s, e - s + 1).c_str()));
    }
    dp[{s, e}] = rst;
    return rst;
  }
  map<pair<int, int>, vector<int>> dp;
};

int main() {
  Solution s;
  //  auto rst = s.diffWaysToCompute("2-1-1");
  auto rst = s.diffWaysToCompute("2*3-4*5");
  for (const auto& item : rst) {
    cout << item << endl;
  }
}