// LEETCODE 2418

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v;
        for (int i = 0; i < names.size(); i++) {
            v.push_back({heights[i], names[i]});
        }

        sort(v.rbegin(), v.rend());  // Sort in descending order

        vector<string> ans(names.size());
        for (int i = 0; i < v.size(); i++) {
            ans[i] = v[i].second;
        }

        return ans;
    }
};