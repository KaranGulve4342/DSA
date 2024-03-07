// LEETCODE 1551

class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        int sum = 0;
        for(int i = 0;i < n;i++){
            arr[i] = (2*i+1);
            sum += arr[i];
        }
        int target = sum/n;
        int diff = 0;
        for(int i = 0;i < n;i++){
            int x = abs(target - arr[i]);
            diff += x;
        }
        return diff/2;
    }
};