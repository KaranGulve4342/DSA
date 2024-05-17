// LEETCODE 2032

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;

        vector<int> temp(110, 0);

        for(auto num : nums1){
            if(temp[num] == 0){
                temp[num] = 1;
            }
        }

        for(auto num : nums2){
            if(temp[num] == 0){
                temp[num] = 2;
            }
            else if(temp[num] == 1){
                ans.push_back(num);
                temp[num] = -1;
            }
        }

        for(auto num : nums3){
            if(temp[num] == 1 || temp[num] == 2){
                ans.push_back(num);
                temp[num] = -1;
            }
        }

        return ans;
    }
};