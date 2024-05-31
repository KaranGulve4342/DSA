// LEETCODE 137

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++){
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << singleNumber(nums) << endl;
    return 0;
}