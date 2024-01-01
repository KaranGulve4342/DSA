// LC 2640
/*
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {       
        int n = nums.size();
        vector<long long> conversion(n,0);
        conversion[0] = 2*nums[0];
        int maxEle = nums[0];
        for(int i = 1;i < n;i++){
            maxEle = max(maxEle,nums[i]);
            conversion[i] = nums[i] + maxEle + conversion[i - 1];
        }

        return conversion;
    }
};
*/