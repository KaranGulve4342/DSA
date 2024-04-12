//  LEETCODE 789

class Solution {
public:

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int myDistance = abs(target[0]) + abs(target[1]);

        for(auto ghost : ghosts){
            int ghostDistance = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);

            if(myDistance >= ghostDistance) return false;
        }
        return true;

    }
};