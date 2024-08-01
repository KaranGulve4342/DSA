// LEETCODE 2678

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(auto citizen : details){
            if(stoi(citizen.substr(11, 2)) > 60){
                count++;
            }
        }

        return count;
    }
};