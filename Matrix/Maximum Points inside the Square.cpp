// LEETCODE 3143

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();

        for(int i = 0;i < n;i++){
            points[i][0] = abs(points[i][0]);
            points[i][1] = abs(points[i][1]);
        }

        int lo = 0;
        int hi = 1e9;
        int ans = 0;

        while(lo <= hi){
            int mid = (lo + (hi - lo)/2);
            unordered_map<char, int> charCount;
            bool flag = true;

            for(int i = 0;i < n;i++){
                if(points[i][0] <= mid && points[i][1] <= mid){
                    charCount[s[i]]++;
                }
            }

            for(auto it : charCount){
                if(it.second > 1){
                    flag = false;
                    break;
                }
            }

            if(flag == true){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        int count = 0;
        for(int i = 0;i < n;i++){
            if(points[i][0] <= ans && points[i][1] <= ans){
                count++;
            }
        }
        return count;
    }
};