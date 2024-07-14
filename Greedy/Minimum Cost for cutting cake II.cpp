// LEETCODE 3219

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<long long, char>> cuts;

        for(long long i = 0;i < horizontalCut.size();i++){
            cuts.push_back({horizontalCut[i], 'H'});
        }
        for(long long i = 0;i < verticalCut.size();i++){
            cuts.push_back({verticalCut[i], 'V'});
        }

        sort(cuts.rbegin(), cuts.rend());

        long long hp = 1;
        long long vp = 1;
        long long ans = 0;

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