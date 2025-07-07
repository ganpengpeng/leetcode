#pragma once

#include <algorithm>
#include <climits>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void PrintVector(const std::vector<int>& v) {
  if (v.empty()) {
    std::cout << "empty vector" << std::endl;
    return;
  }
  std::cout << v.front();
  for (int i = 1; i < v.size(); ++i) {
    std::cout << ", " << v[i];
  }
}

void Print2DVector(const std::vector<std::vector<int>>& v) {
  if (v.empty()) {
    std::cout << "empty 2d vector" << std::endl;
    return;
  }
  for (const auto& i : v) {
    PrintVector(i);
    std::cout << std::endl;
  }
}