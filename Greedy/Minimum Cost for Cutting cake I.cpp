// LEETCODE 3218

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int, char>> cuts;

        for(int i = 0;i < horizontalCut.size();i++){
            cuts.push_back({horizontalCut[i], 'H'});
        }
        for(int i = 0;i < verticalCut.size();i++){
            cuts.push_back({verticalCut[i], 'V'});
        }

        sort(cuts.rbegin(), cuts.rend());

        int hp = 1;
        int vp = 1;
        int ans = 0;

        for(auto cut : cuts){
            if(cut.second == 'H'){
                ans += (cut.first * vp);
                hp += 1;
            }
            else{
                ans += (cut.first * hp);
                vp += 1;
            }
        }

        return ans;
    }
};