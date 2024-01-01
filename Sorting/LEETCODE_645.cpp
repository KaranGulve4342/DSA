#include<iostream>
#include<vector>
using namespace std;

int duplicateNumber(vector<int>& nums){
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
int missingNumber(vector<int>& nums){
    int n=  nums.size();
    int i = 0;

    while(i < n){
        if(nums[i] <= 0) i++;
        else if(nums[i] <= 0 || nums[i] > n || nums[i] == i+1 || nums[nums[i] - 1] == nums[i]) i++;
        else swap(nums[i],nums[nums[i]-1]);
    }
    for(int i = 0;i < n;i++){
        if(nums[i] != i+1) return i+1;
    }
    return n+1;
}
int main(){
    vector<int> nums = {1,1};
    vector<int> ans;
    ans.push_back(duplicateNumber(nums));
    ans.push_back(missingNumber(nums)) ;
    cout<<"["<<ans[0]<<","<<ans[1]<<"]";
    return 0;
}