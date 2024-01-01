// LEETCODE 6

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string convert(string s int numRows){
        int len = s.length();

        if(numRows == 1 || numsRows >= len){
            return s;
        }
        int direction = -1;// to keep track of the direction we are supposed to move in
        // either up or down
        // 1 means down and -1 means up

        int row = 0;// the row number where we are going to append the current character

        vector<char> result[numRows];

        for(auto c : s){
            result[row].push_back(c);

            if(row == 0 || row == numRows - 1) // change direction
            {
                drection *= -1;
            }
            row += direction;
        }

        string ans = "";

        for(auto x : result){
            for(auto y : x){
                ans += y;
            }
        }
        return ans;
    }
};

int main()
{
    
    
    return 0;
}