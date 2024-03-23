// LEETCODE 2571

class Solution {
public:
    vector<int> arr;
    int solve(int n){
        int val = INT_MAX;

        for(int i = 0;i < arr.size();i++){
            int diff = abs(arr[i] - n);
            val = min(val, diff);
        }
        return val;
    }
    int minOperations(int n) {
        int ans = 0;
        for(int i = 0;i <= 16;i++){
            int x = pow(2, i);
            arr.push_back(x);
        }
        while(n != 0){
            n = solve(n);
            ans++;
        }
        return ans;
    }
};