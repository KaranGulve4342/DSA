// LEETCODE 34

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int start = -1;
        int end = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                start = mid;
                end = mid;

                while(start > 0 && nums[start-1] == target){
                    start--;
                }
                while(end < nums.size() - 1 && nums[end+1] == target){
                    end++;
                }
                break;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return {start, end};
    }
};
int main(){

    return 0;
}
