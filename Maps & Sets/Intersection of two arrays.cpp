// LEETCODE 349
/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numCount;
        unordered_set<int> result;

        for(int num : nums1){
            numCount[num]++;
        }

        for(int num : nums2){
            if(numCount.find(num) != numCount.end() && numCount[num] > 0){
                result.insert(num);
                numCount[num]--;
            }
        }
        vector<int> ans(result.begin(), result.end());
        return ans;

    }
};
*/