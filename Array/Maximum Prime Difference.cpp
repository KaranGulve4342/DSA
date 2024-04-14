// LEETCODE 3115

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1){
            return false;
        } 
        if (n <= 3){
            return true;
        }

        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<pair<int, int>> vp;
        for(int i = 0;i < nums.size();i++){
            if(isPrime(nums[i])){
                vp.push_back({i, nums[i]});
            }
        }
        if(vp.size() == 1){
            return 0;
        }
        sort(vp.begin(), vp.end());
        return vp[vp.size() - 1].first - vp[0].first;
            
    }
};