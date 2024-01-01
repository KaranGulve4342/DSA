// LEETCODE 506

/*
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);

        priority_queue<pair<int, int>> pq;

        for(int i = 0;i < n;i++){
            pq.push({score[i],i});
        }

        unordered_map<int, string> umap;
        umap[1] = "Gold Medal";
        umap[2] = "Silver Medal";
        umap[3] = "Bronze Medal";

        for(int i = 1;!pq.empty();i++){
            int idx = pq.top().second;
            pq.pop();
            if(i <= 3){
                ans[idx] = umap[i];
            }
            else{
                ans[idx] = to_string(i);
            }
        }
        return ans;

        
    }
};
*/