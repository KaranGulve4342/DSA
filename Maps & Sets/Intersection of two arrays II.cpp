// LEETCODE 350

/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numCount;
        vector<int> ans;
        for(int num : nums1){
            numCount[num]++;
        }

        for(int num : nums2){
            if(numCount.find(num) != numCount.end() && numCount[num] > 0){
                ans.push_back(num);
                numCount[num]--;
            }
        }
        
        return ans;

    } 
};

*/