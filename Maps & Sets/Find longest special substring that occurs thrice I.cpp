// LEETCODE 2981

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> umap;
        int count = 0;

        for(int i = 0;i < s.length();i++){
            count = 1;

            umap[{s[i], count}]++;

            for(int j = i;j < s.length();j++){
                if(s[j] == s[j+1]){
                    count++;
                    umap[{s[i], count}]++;
                }
                else{
                    break;
                }
            }
        }
        int ans = 0;

        for(auto x : umap){
            if(x.second >= 3){
                ans = max(ans, x.first.second);
            }
        }

        return ans == 0 ? -1 : ans;
    }
};