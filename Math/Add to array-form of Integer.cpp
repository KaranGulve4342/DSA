// LEETCODE 989

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // long long number = 0;
        // vector<int> ans;
        // for(int i = 0;i < num.size();i++){
        //     number*=10;
        //     number += num[i];
        // }
        // cout<<number;
        // number += k;

        // while(number > 0){
        //     int x = number%10;
        //     ans.push_back(x);
        //     number /= 10;
        // }
        // reverse(ans.begin(), ans.end());

        for(int i = num.size() - 1;i >= 0;i--){
            int sum = num[i] + k;
            num[i] = sum%10;
            k = sum/10;
        }
        // if(k > 0){
        //     num.insert(num.begin(), k);
        // }
        while(k > 0){
            num.insert(num.begin(), k%10);
            k/=10;
        }
        return num;
    }
};