// LEETCODE 1387

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n){
        if(n == 1) return 0;
         return (n % 2 == 0) ? solve(n/2) + 1 : solve(3*n + 1) + 1;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > ans;

        for(int i = lo;i <= hi;i++){
            ans.push_back({solve(i), i});
        }

        sort(ans.begin(), ans.end());

        return ans[k-1].second;
    }
};

int main()
{
    
    
    return 0;
}