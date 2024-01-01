// LEETCODE 204

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n){
        if(n == 1) return false;
        for(int i = 2;i <= sqrt(n);i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2;i*i < n;i++){
            if(isPrime[i] == true){
                for(int j = 2*i;j < n;j += i){
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2;i < n;i++){
            if(isPrime[i] == true){
                count++;
            }
        }
        return count;
    }
};

int main()
{
    
    
    return 0;
}