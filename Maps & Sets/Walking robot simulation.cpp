// LEETCODE 874

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int x = 0;
        int y = 0;
        int idx = 0; 

        set<pair<int, int>> st;
        for(auto obstacle : obstacles){
            st.insert({obstacle[0], obstacle[1]});
        }

        int res = 0;

        for(auto command : commands){
            if(command == -2){
                
                idx = (idx + 3) % 4;
            }
            else if(command == -1){
                
                idx = (idx + 1) % 4;
            }
            else{
                for(int i = 0; i < command; i++){
                    int newX = x + dirs[idx].first;
                    int newY = y + dirs[idx].second;

                    if(st.find({newX, newY}) == st.end()){
                        x = newX;
                        y = newY;
                        res = max(res, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};