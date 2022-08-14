#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a.front() < b.front();
        });
        for(auto a = intervals.begin(), b = a + 1; b < intervals.end(); b = a + 1) {
            if(a->back() >= b->front()) {
                a->back() = b->back();
                intervals.erase(b);
            } else {
                a += 1;
            }
        }
        return intervals;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    intervals = s.merge(intervals);
    for (const auto &pair: intervals) {
        cout << pair.front() << " " << pair.back() << endl;
    }
    int a = INT32_MIN;
}