// leetcode 01

/*
class Solution{
public:
    vector<int>twoSum(vector<int>& numa, int target){
        vector<int> indices;
        int n = nums.size();
        for(int i = 0;i < n-1;i++){
            for(int j = i + 1;j < n;j++){
                if(nums[i] + nums[j] == target){
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }
}
*/

/*
class OSlution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ans;
        int n = nums.size();
        unordered_map<<int ,int>m;
        for(int i = 0;i < n;i++){
            int rem = target - nums[i];
            if(m.find(rem) != m.end()){
                ans.ppush_back(m[rem]);
                ans.push_back(i);
            }
            else m[nums[i]] = i;
        }
        return ans;

    }
}
*/