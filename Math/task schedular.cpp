// LEETCODE 621

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> umap;
        int maxCount = 0;
        for(int i = 0;i < tasks.size();i++){
            umap[tasks[i]]++;
        }

        for(auto x : umap){
            maxCount = max(maxCount, x.second);
        }

        int time = (maxCount - 1) * (n+1);
        for(auto x : umap){
            if(x.second == maxCount){
                time++;
            }
        }
        return max((int)tasks.size(), time);
    }
};