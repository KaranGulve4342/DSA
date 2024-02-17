// LEETCODE 2023

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        int n = target.length();

        unordered_map<string, int> umap;
        for(auto num : nums){
            umap[num]++;
        }

        for(int i = 0;i < n;i++){
            string s1 = target.substr(0, i);
            string s2 = target.substr(i, n);

            if(s1 == s2){
                count += (umap[s1] * (umap[s2] - 1));
            }
            else{
                count += (umap[s1] * umap[s2]);
            }
        }

        return count;
    }
};