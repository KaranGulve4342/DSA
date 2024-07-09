// LEETCODE 1701 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();

        double nextIdleTime = 0.0;
        double netWaitTime = 0.0;

        for(int i = 0;i < customers.size();i++){
            nextIdleTime = max((double)customers[i][0], nextIdleTime) + customers[i][1];

            netWaitTime = netWaitTime + nextIdleTime - (double)customers[i][0];
        }

        double avgWaitTime = netWaitTime/n;

        return avgWaitTime;
    }
};