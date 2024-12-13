// LEETCODE 2593

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0;i < n;i++){
            pq.push({nums[i], i});
        }

        long long score = 0;

        unordered_set<int> marked_index;

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int ele = t.first;
            int index = t.second;

            if(marked_index.find(index) != marked_index.end()){
                continue;
            }

            score += ele;
            marked_index.insert(index);
            marked_index.insert(index + 1);
            marked_index.insert(index - 1);
        }

        return score;
    }
};