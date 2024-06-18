// LEETCODE 826

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // Sort jobs by difficulty
        sort(jobs.begin(), jobs.end());
        
        // Sort worker array
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0, totalProfit = 0, jobIndex = 0;
        
        for (int ability : worker) {
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= ability) {
                maxProfit = max(maxProfit, jobs[jobIndex].second);
                ++jobIndex;
            }
            // Add the best profit this worker can make
            totalProfit += maxProfit;
        }
        
        return totalProfit;
    }
};