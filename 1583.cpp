#include "common.h"

using namespace std;

class Solution {
 public:
  map<int, int> p;
  int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    for (auto& v : pairs) {
      p[v[0]] = v[1];
      p[v[1]] = v[0];
    }
    int rst = 0;
    for (auto& pair : pairs) {
      if (IsUnhappy(preferences, pair[0])) {
        rst += 1;
      }
      if (IsUnhappy(preferences, pair[1])) {
        rst += 1;
      }
    }
    return rst;
  }

  bool IsUnhappy(vector<vector<int>>& preferences, int a) {
    auto b = p[a];
    auto& pa = preferences[a];
    for (auto pa1 : pa) {
      if (pa1 == b) {
        return false;
      }
      int pa1p = p[pa1];
      for (auto pb1 : preferences[pa1]) {
        if (pb1 == a) {
          return true;
        }
        if (pb1 == pa1p) {
          break;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  int n = 4;
  vector<vector<int>> a = {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}};
  vector<vector<int>> b = {{0, 1}, {2, 3}};
  // int n = 4;
  // vector<vector<int>> a = {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}};
  // vector<vector<int>> b = {{1, 3}, {0, 2}};
  cout << s.unhappyFriends(n, a, b) << endl;
  return 0;
}