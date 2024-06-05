// leetcode 875

/*
class Solution{
public:
    bool check(int speed, vector<int>& piles, int h){
        long long count = 0;
        int n = piles.size();
        for(int i = 0;i < n;i++){
            // if(count > h) return false;
            if(speed >= piles[i]) count++;
            else if(piles[i] % speed == 0) count += (long long)(piles[i]/speed);
            else count += (long long)(piles[i]/speed + 1);

        }
        if(count > (long long)h) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piler, int h){
        int n = piles.size();
        int mx = -1;
        for(int i = 0;i < n;i++){
            mx = max(mx, piles[i]);
        }
        int lo = 1;
        int hi = mx;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid, piles, h) == true){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long calculateTotalHours(vector<int> &v, long long hourly) {
        long long totalH = 0;
        long long n = v.size();
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int> v, int h) {
        long long lo = 1;
        long long hi = *max_element(v.begin(), v.end());

        //apply binary search:
        while (lo <= hi) {
            long long mid = lo + (hi - lo)/2;
            long long totalH = calculateTotalHours(v, mid);
            if (totalH <= h) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return (int)lo;
    }
};

