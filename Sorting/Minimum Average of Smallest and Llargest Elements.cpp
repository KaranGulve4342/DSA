// LEETCPDE 3194

// Minimum Average of Smallest and Largest Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = n-1;

        vector<double> avg;
        while(lo < hi){
            double x = (nums[lo] + nums[hi])/2.0;
            avg.push_back(x);
            lo++;
            hi--;
        }

        return *min_element(avg.begin(), avg.end());
    }
};