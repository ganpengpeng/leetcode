#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
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

using namespace std;

long long mod = 1e9 + 7;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
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

void PrintList(ListNode* head) {
  while (head) {
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
}