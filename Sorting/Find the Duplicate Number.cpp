// LC_287
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // int len = nums.size();
        // int i = 0;
        // while(i < len)
        // {
        //     int correctIdx = nums[i];
        //     if(nums[correctIdx] == nums[i]) return nums[i];
        //     else swap(nums[i],nums[correctIdx]);
        // }
        // return 1;
        /*
        int n = nums.size();
        int start = 1;
        int end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start)/2;
            int count = 0;
            for(int i = 0;i < n;i++){
                if(nums[i] <= mid){
                    count++;
                }   
            }
            if(count <= mid){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return start;
        */

        

        for(int i = 0;i < nums.size();i++){
            while(nums[i] != i + 1){
                if(nums[nums[i]-1] == nums[i]){
                    return nums[i];
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return -1;
    }
};

*/