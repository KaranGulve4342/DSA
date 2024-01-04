// LEETCODE 2870

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=  nums.size();
        unordered_map<int, int> umap;
        
        for(int i =0;i < n;i++){
            umap[nums[i]]++;
        }
        int operations = 0;
        for(auto x : umap){
            int val = x.second;

            if(val == 1) return -1;

            if(val % 3 == 0){
                operations += (val/3);
            }
            else{
                if(val % 3 == 1){
                    operations += val/3 + 1;
                }
                else if(val % 3 == 2){
                    operations += val/3 + 1;
                }
            }
        }
        return operations;
    }
};