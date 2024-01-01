// LEETCODE 1759

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define MOD 1000000007;
    int countHomogenous(string s) {
        long long result = 0;
        int start = 0;

        for(int i = 0;i < s.length();i++){
            if(s[i] != s[start]){
                int appear = i - start;
                while(appear > 0){
                    result += appear;
                    appear--;
                }
                start = i;
            }
        }
        int appear = s.length() - start;
        while(appear > 0){
            result += appear;
            appear--;
        }
        return result % MOD;

    }
};

int main()
{
    
    
    return 0;
}