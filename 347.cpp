#include "common.h"

using namespace std;

class Solution {
  unordered_map<int, int> counts;

public:
  int partition(vector<int>& uni_nums, int l, int r) {
    if (l == r) {
      return l;
    }
    int pivot = (l + r) / 2;
    swap(uni_nums[pivot], uni_nums[r]);
    int i, j;
    i = j = l;
    while (j < r) {
      if (counts[uni_nums[j]] < counts[uni_nums[r]]) {
        swap(uni_nums[j], uni_nums[i++]);
      }
      j += 1;
    }
    swap(uni_nums[i], uni_nums[r]);
    return i;
  }

  void quickSelect(vector<int>& uni_nums, int l, int r, int count) {
    if (l == r) {
      return;
    }
    int pivot = partition(uni_nums, l, r);
    while (pivot != count) {
      if (pivot < count) {
        l = pivot + 1;
      } else {
        r = pivot - 1;
      }
      pivot = partition(uni_nums, l, r);
    }
  }

  vector<int> topKFrequent(vector<int>& nums, int k) {
    for (auto n : nums) {
      counts[n] += 1;
    }
    vector<int> uni_nums;
    uni_nums.reserve(counts.size());
    for (auto n : counts) {
      uni_nums.push_back(n.first);
    }
    if (uni_nums.size() == k) {
      return uni_nums;
    }
    quickSelect(uni_nums, 0, uni_nums.size() - 1, uni_nums.size() - k);
    vector<int> rst(k);
    copy(uni_nums.begin() + uni_nums.size() - k, uni_nums.end(), rst.begin());
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {5, 3, 1, 1, 1, 3, 73, 1};
  auto rst = s.topKFrequent(v, 2);
  for (auto n : rst) {
    cout << n << ", ";
  }
  cout << endl;
  return 0;
}
