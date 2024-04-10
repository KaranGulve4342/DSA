// LEETCODE 2177

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans = {};
        if(num % 3 != 0){
            return ans;
        }

        long long min = num / 3;
        ans.push_back(min - 1);
        ans.push_back(min);
        ans.push_back(min+1);

        return ans;
    }
};