#include "common.h"

class Solution {
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    this->price = price;
    this->special = special;
    this->needs = needs;
    item_num = price.size();
    func(0, needs, 0);
    return rst;
  }

  void func(int pos, vector<int>& needs, int cost) {
    if (pos == special.size()) {
      for (auto i = 0; i < item_num; ++i) {
        cost += price[i] * needs[i];
      }
      if (cost < rst) {
        rst = cost;
      }
      return;
    }
    int n = 0;
    while (true) {
      bool valid = true;
      for (auto i = 0; i < item_num; ++i) {
        if (needs[i] < special[pos][i] * n) {
          valid = false;
          break;
        }
      }
      if (!valid) {
        break;
      }
      for (auto i = 0; i < item_num; ++i) {
        needs[i] -= special[pos][i] * n;
      }
      func(pos + 1, needs, cost + special[pos][item_num] * n);
      for (auto i = 0; i < item_num; ++i) {
        needs[i] += special[pos][i] * n;
      }
      n += 1;
    }
  }

  vector<int> price;
  vector<vector<int>> special;
  vector<int> needs;
  int item_num;
  int rst = INT_MAX;
};

int main() {
  Solution s;
  //  vector<int> price = {2, 5};
  //  vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
  //  vector<int> needs = {3, 2};
  //  vector<int> price = {2, 3, 4};
  //  vector<vector<int>> special = {{1, 1, 0, 4}, {2, 2, 1, 9}};
  //  vector<int> needs = {1, 2, 1};
  vector<int> price = {9, 9};
  vector<vector<int>> special = {{1, 1, 1}};
  vector<int> needs = {2, 2};
  cout << s.shoppingOffers(price, special, needs) << endl;
}