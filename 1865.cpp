#include "common.h"

class FindSumPairs {
 public:
  FindSumPairs(vector<int> nums1, vector<int> nums2) {
    this->nums1.swap(nums1);
    std::sort(nums1.begin(), nums1.end());
    this->nums2.swap(nums2);
    for (auto i = 0; i < this->nums2.size(); ++i) {
      m[this->nums2[i]] += 1;
    }
  }

  void add(int index, int val) {
    int n = nums2[index];
    nums2[index] += val;
    m[n] -= 1;
    m[nums2[index]] += 1;
  }

  int count(int tot) {
    int ans = 0;
    for (const auto& item : nums1) {
      int target = tot - item;
      if (target <= 0) {
        continue;
      }
      ans += m[target];
    }
    return ans;
  }

  vector<int> nums1, nums2;
  unordered_map<int, int> m;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
int main() {
  FindSumPairs s({1, 1, 2, 2, 2, 3}, {1, 4, 5, 2, 5, 4});
  cout << s.count(7) << endl;
}