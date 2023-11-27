#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long max = 0;
    int maxArea(vector<int>& height) {
        for(auto begin = height.begin(), end = height.end() - 1; begin < end;) {
            max = std::max(max, std::min(*begin, *end) * (end - begin));
            if(*begin < * end) {
                begin += 1;
            } else {
                end -= 1;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 1};
    v.front();
    s.maxArea(v);
}