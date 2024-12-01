// LEETCODE 3371

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // int maxi = *min_element(nums.begin(), nums.end());
        int maxi = INT_MIN;
        unordered_map<int, int> umap;
        for(auto num : nums){
            umap[num]++;
            sum += num;
        }

        for(auto num : nums){
            umap[num]--;

            int candidate_outlier = sum - (2*num);

            if(umap[candidate_outlier] > 0){
                maxi = max(maxi, candidate_outlier);
            }
            umap[num]++;
        }

        return maxi;
    }
};