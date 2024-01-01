#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    vector<int> nums = {1};
    set<int> ans;
    for(int i = 0;i < nums.size();i++){
        while(nums[i] != i + 1){
            if(nums[nums[i]-1] == nums[i]){
                ans.insert(nums[i]);
                break;
            }
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}