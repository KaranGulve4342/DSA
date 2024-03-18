// LEETCODE 452

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> vp;
        for(auto point : points){
            vp.push_back({point[0], point[1]});
        }
        sort(vp.begin(), vp.end());
        int lastpoint = vp[0].second;
        int arrows = 1;
        for(int i = 0;i < vp.size();i++){
            if(vp[i].first > lastpoint){
                arrows++;
                lastpoint = vp[i].second;
            }
            lastpoint = min(vp[i].second, lastpoint);
        }
        return arrows;
    }
};