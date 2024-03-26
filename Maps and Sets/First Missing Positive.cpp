// LEETCODE 41

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int missingNumber = 1;
        // sort(nums.begin(), nums.end());

        // for(int i = 0;i < nums.size();i++){
        //     if(nums[i] > 0){
        //         if(nums[i] == missingNumber){
        //             missingNumber++;
        //         }
        //         else if(nums[i] > missingNumber){
        //             break;
        //         }
        //     }
        // }
        // return missingNumber;
        set<int> st;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > 0){
                st.insert(nums[i]);
            }
        }
        int count = 1;
        while(st.size() != 0){
            if(*st.begin() == count){
                st.erase(*st.begin());
                ++count;
            }
            else{
                break;
            }
        }
        return count;
    }
};