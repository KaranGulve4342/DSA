// LEETCODE 75

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int lo = 0;
        int mid = 0;
        int hi = nums.size() - 1;

        while(mid <= hi){
            if(nums[mid] == 0){
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[hi]);
                hi--;
            }
        }
    }
};