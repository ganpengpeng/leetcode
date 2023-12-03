#include "common.h"

using namespace std;

class Trie {
  vector<Trie*> childrens;
  bool leaf;

  Trie* searchPrefix(const string& word) {
    auto* node = this;
    for (auto c : word) {
      int index = c - 'a';
      if (node->childrens[index] == nullptr) {
        return nullptr;
      }
      node = node->childrens[index];
    }
    return node;
  }

public:
  Trie()
    : childrens(26), leaf(false) {
  }

  void insert(string word) {
    auto* node = this;
    for (auto c : word) {
      const int index = c - 'a';
      if (node->childrens[index] == nullptr) {
        node->childrens[index] = new Trie();
      }
      node = node->childrens[index];
    }
    node->leaf = true;
  }

  bool search(string word) {
    auto* node = searchPrefix(word);
    return node && node->leaf;
  }

  bool startsWith(string prefix) {
    auto* node = searchPrefix(prefix);
    return node != nullptr;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie* obj = new Trie();
  obj->insert("apple");
  obj->search("apple");
  return 0;
}
