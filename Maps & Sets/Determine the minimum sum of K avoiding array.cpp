// LEETCODE 2829

class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> uset;
        int i = 1;
        while(uset.size() != n){
            if(uset.find(k-i) == uset.end()){
                uset.insert(i);
            }
            i++;
        }
        int sum = 0;
        for(auto x : uset){
            sum += x;
        }
        return sum;
    }
};