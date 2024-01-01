// LEETCODE 2785

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;

        for(char c : s){
            if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u'){
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());
        string ans;
        int index = 0;

        for(char c : s){
            if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u'){
                ans.push_back(vowels[index++]);
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main()
{
    
    
    return 0;
}