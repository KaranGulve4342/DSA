// LEETCODE 1552

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canPlaceBalls(int x, vector<int>& position, int m){
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        for(int i = 1;i < position.size() && ballsPlaced < m;i++){
            int currPos = position[i];

            if(currPos - prevBallPos >= x){
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        return ballsPlaced == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;

        int n = position.size();

        sort(position.begin(), position.end());

        int lo = 1;
        int hi = ceil(position[n-1]/(m - 1.0));

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(canPlaceBalls(mid, position, m)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};