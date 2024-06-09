// LEETCODE 3174

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        while(true){
            int position = -1;
            for(int i = 0;i < s.length();i++){
                if(isdigit(s[i])){
                    position = i;
                    break;
                }
            }

            if(position == -1){
                break;
            }

            int nonPosition = -1;
            for(int i = position - 1;i >= 0;i--){
                if(!isdigit(s[i])){
                    nonPosition = i;
                    break;
                }
            }

            if(nonPosition != -1){
                s.erase(position, 1);
                s.erase(nonPosition, 1);
            }
        }

        return s;
    }
};