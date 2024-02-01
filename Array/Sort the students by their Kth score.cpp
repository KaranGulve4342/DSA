// LEETCODE 2545

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int, vector<int>>> ans;

        for(auto sc : score){
            ans.emplace_back(sc[k], sc);
        }

        sort(ans.begin(), ans.end());
        vector<vector<int> >result;
        for(auto x : ans){
            result.push_back(x.second);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};