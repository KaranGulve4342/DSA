// LEETCODE 2601

class Solution {
public:
    bool isPrime(int x){
        if(x == 1){
            return false;
        }

        for(int i = 2;i*i <= x;i++){
            if(x%i == 0){
                return false;
            }
        }

        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int p = 0;

        for(auto num : nums){
            if(num <= p){
                return false;
            }

            int prime = num - p - 1;

            while(prime > 0 && !isPrime(prime)){
                prime--;
            }

            if(prime == 0){
                p = num;
            }
            else{
                p = num - prime;
            }
        }
        return true;
    }
};