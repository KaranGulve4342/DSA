// LEETCODE 2079

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int c = capacity;
        int n = plants.size();
        for(int i = 0;i < n;i++){
            if(c >= plants[i]){
                ans++;
            }
            else{
                ans += i;
                ans += i+1;
                c = capacity;
            }
            c -= plants[i];
        }

        return ans;
    }
};