// LEETCODE 3
#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    
    return 0;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int start = 0;
        int maxLength = 0;
        for(int i = 0;i < s.length();i++){
            if(umap.find(s[i]) != umap.end()){
                start = max(start, umap[s[i]]+1);
            }
            umap[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};