// LEETCODE 252

#include <iostream>
#include <vector>
using namespace std;

bool canAttend(vector<vector<int>>& intervals) {
    if(intervals.empty()) return true;
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < intervals[i - 1][1])
            return false;
    }
    return true;
}

int main() {
    vector<vector<int>> intervals = {{0,7}, {5, 10}, {15, 20}};
    cout << (canAttend(intervals) ? "true" : "false") << endl;
    return 0;
}
