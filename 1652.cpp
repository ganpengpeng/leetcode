#include "common.h"

using namespace std;

class Solution {
  vector<int> cumulate;

 public:
  vector<int> decrypt(vector<int>& code, int k) {
    cumulate.resize(code.size());
    cumulate[0] = code[0];
    for (int i = 1; i < code.size(); ++i) {
      cumulate[i] = cumulate[i - 1] + code[i];
    }

    vector<int> rst(code.size());
    if (k > 0) {
      for (int i = 0; i < rst.size(); ++i) {
        rst[i] = GetSum(i, (i + k) % code.size());
      }
    } else if (k < 0) {
      for (int i = 0; i < rst.size(); ++i) {
        rst[i] = GetSum((i + k - 1 + code.size()) % code.size(), (i - 1 + code.size()) % code.size());
      }
    }
    return rst;
  }
  int GetSum(int i, int j) {
    if (i <= j) {
      return cumulate[j] - cumulate[i];
    }
    return cumulate.back() - cumulate[i] + cumulate[j];
  }
};

int main() {
  Solution s;
  vector<int> v = {10, 5, 7, 7, 3, 2, 10, 3, 6, 9, 1, 6};
  auto t = s.decrypt(v, -4);
  for (auto v1 : t) {
    cout << v1 << endl;
  }
  return 0;
}