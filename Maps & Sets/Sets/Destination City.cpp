// LEETCODE 1436

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> set;

        for(const auto &path : paths){
            set.insert(path[0]);
        }

        for(const auto &path : paths){
            if(set.find(path[1]) == set.end()){
                return path[1];
            }
        }
        return "";
    }
};