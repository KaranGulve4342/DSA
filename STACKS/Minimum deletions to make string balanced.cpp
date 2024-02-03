// LEETCODE 1653

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int i = 0;
        int count = 0;

        while(i < s.length()){
            while(i < s.length() && !st.empty() && s[i] == 'a' && st.top() == 'b'){
                st.pop();
                i++;
                count++;
            }

            if(i < s.length()){
                st.push(s[i]);
            }
            i++;
        }
        return count;
    }
};