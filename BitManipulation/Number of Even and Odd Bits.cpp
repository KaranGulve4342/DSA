// LEETCODE 2595

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        int idx = 0;
        while(n){
            if(n&1 && (idx % 2 == 0)) even++;
            if(n&1 && (idx % 2 != 0)) odd++;
            idx++;
            n >>= 1;
        }
        // cout<<__builtin_ctz(16)<<endl;
        // cout<<__builtin_ctz(20)<<endl;
        // cout<<__builtin_ctz(18)<<endl;
        return {even, odd};
    }
};