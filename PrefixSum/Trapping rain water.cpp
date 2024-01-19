// LEETCODE 42

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int trap(vector<int>& height){
        int n = height.size();

        vector<int> right(n);
        vector<int> left(n);

        for(int i = 1;i < n;i++){
            left[i] = max(left[i-1], height[i]);
        }

        for(int i = n-2;i >= 0;i--){
            right[i] = max(right[i+1], height[i]);
        }

        int ans = 0;
        for(int i = 0;i < n;i++){
            ans +=(min(right[i], left[i]) - a[i]);
        }

        return ans;
    }
}