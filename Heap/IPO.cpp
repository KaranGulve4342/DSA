// LEETCODE 502

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);

        for(int i = 0;i < n;i++){
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;

        while(k--){
            while(i < n && projects[i].first <= w){
                maximizeCapital.push(projects[i].second);
                i++;
            }

            if(maximizeCapital.size() == 0){
                break;
            }

            w += maximizeCapital.top();
            maximizeCapital.pop();
        }

        return w;
    }
};