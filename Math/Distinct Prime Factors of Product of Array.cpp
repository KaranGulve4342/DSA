// LEETCODE 2521

class Solution {
public:
    void addPrimeFactors(unordered_set<int> &st, int num){
        int divisor = 2;
        while(num > 1){
            if(num % divisor == 0){
                st.insert(divisor);
                num /= divisor;
            }
            else{
                divisor++;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num : nums){
            addPrimeFactors(st, num);
        }
        return st.size();
    }
};