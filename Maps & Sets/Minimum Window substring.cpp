// LEETCODE 76

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length() < t.length()){
            return "";
        }

        unordered_map<int, int> umap;
        int count = t.length();
        int start = 0;
        int end = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for(char ch : t){
            umap[ch]++;
        }

        while(end < s.length()){
            if(umap[s[end++]]-- > 0){
                count--;
            }

            while(count == 0){
                if(end - start < minLen){
                    startIdx = start;
                    minLen = end - start;
                }

                if(umap[s[start++]]++ == 0){
                    count++;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};