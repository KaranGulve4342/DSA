// LEETCODE 1337

/*
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = 0;j < m;j++){
                sum += mat[i][j];
            }

            pq.push({sum, i});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
*/