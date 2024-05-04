// LEETCODE 1404

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int counterOneAdd = 0;
        int carry = 0;

        for(int i = s.length() - 1;i > 0;i--){
            counterOneAdd++;

            if(s[i] - '0' + carry == 1){
                carry = 1;
                counterOneAdd++;
            }
        }
        return counterOneAdd + carry;
    }
};