// LEETCODE 2225

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;

        for (auto match : matches) {
            losses[match[1]]++;
        }

        vector<int> notLost, lostOnce;

        for(auto match : matches){
            if(losses.find(match[0]) == losses.end()){
                losses[match[0]] = 0;
            }
        }

        for(auto i : losses){
            if(i.second == 1){
                lostOnce.push_back(i.first);
            }
            if(i.second == 0){
                notLost.push_back(i.first);
            }
        }
        // sort(notLost.begin(), notLost.end());
        // sort(lostOnce.begin(), lostOnce.end());

        return {notLost, lostOnce};
    }
};