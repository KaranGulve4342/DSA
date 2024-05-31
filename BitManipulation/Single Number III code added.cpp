// LEETCODE 260

#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int xor_val = 0;
    for(int i = 0; i < nums.size(); i++){
        xor_val ^= nums[i];
    }
    int mask = 1;
    while((mask & xor_val) == 0){
        mask <<= 1;
    }
    int a = 0, b = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] & mask){
            a ^= nums[i];
        }
        else{
            b ^= nums[i];
        }
    }
    return {a, b};
}

int main(){

}

// METHOD II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int most_significant_bit(long long n){
        int mask = 1;
        while((mask & n) == 0){
            mask = mask << 1;
        }
        return mask;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;

        for (auto num : nums) {
            sum ^= num;
        }

        cout << "Sum after XORing all numbers: " << sum << endl;

        int first = 0;
        int second = 0;

        // int lowbit = sum & (-sum);
        int lowbit = most_significant_bit(sum);

        cout << "Lowbit (rightmost set bit in sum): " << lowbit << endl;

        for (auto num : nums) {
            if (num & lowbit) {
                first ^= num;
            } else {
                second ^= num;
            }
        }

        cout << "First unique number: " << first << endl;
        cout << "Second unique number: " << second << endl;

        return {first, second};
    }
};
