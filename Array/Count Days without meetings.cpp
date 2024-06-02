// LEETCODE 3169

// Given the number of days and a list of meetings, the task is to find the number of days left without any meetings.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());

        int ans = meetings[0][0] - 1;

        int start = meetings[0][0];
        int end = meetings[0][1];

        for(int i = 1;i < n;i++){
            int currStart = meetings[i][0];
            int currEnd = meetings[i][1];

            if(end <= currStart){
                ans += max(0, currStart - end - 1);
                start = currStart;
                end = currEnd;
            }
            else{
                start = min(start, currStart);
                end = max(end, currEnd);
            }
        }

        ans += days - end;

        return ans;
    }
};