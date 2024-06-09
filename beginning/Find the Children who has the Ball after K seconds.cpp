// LEETCODE 3178

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int ans = 0;
        int direction = 1;

        for(int i = 0;i < k;i++){
            ans += direction;
            if(ans == 0){
                direction = 1;
            }
            else if(ans == n-1){
                direction = -1;
            }
        }

        return ans;
    }
};