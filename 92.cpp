#include "common.h"

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    auto* t = new ListNode(0, head);
    auto* new_head = t;
    for (int i = 1; i < left; ++i) {
      t = t->next;
    }
    int n = right - left + 1;
    auto* pre = t->next;
    auto* next = t->next;
    while (n--) {
      auto* temp = next->next; // 3
      next->next = t->next;
      t->next = next;
      pre->next = temp;
      next = temp;
    }
    return new_head->next;
  }
};

int main() {
  Solution s;
  ListNode* head = new ListNode();
  auto* t = head;
  /*for (auto i = 1; i <= 2; ++i) {
    t->next = new ListNode();
    t = t->next;
    t->val = i;
    t->next = nullptr;
  }
  PrintList(head->next);*/
  for (auto i = 1; i <= 5; ++i) {
    t->next = new ListNode();
    t = t->next;
    t->val = i;
    t->next = nullptr;
  }
  PrintList(head->next);
  head = s.reverseBetween(head->next, 2, 4);
  PrintList(head);
}
