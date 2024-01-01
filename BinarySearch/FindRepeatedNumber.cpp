#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums){
    int lo = 0;
    int hi = nums.size() - 1;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        int count = 0;
        for(const int n : nums){
            if(n <= mid){
                count++;
            }
        }

        if(count > mid){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}
int main(){
    vector<int> nums = {1, 2, 3, 3, 4};
    cout<<findDuplicate(nums);
}