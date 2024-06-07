// LEETCODE 1922

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long x, long long n){
        if(n == 0) return 1;

        long long temp = power(x, n/2)%MOD;

        if(n%2 == 0) return (temp*temp)%MOD;
        else return (((x * temp)%MOD)*temp) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long numberofOddPlaces = n/2;
        long long numberofEvenPlaces = n/2 + n%2;

        long long ans = (power(4LL, numberofOddPlaces) % MOD * power(5LL, numberofEvenPlaces) % MOD) % MOD;

        return (int)ans;
    }
};