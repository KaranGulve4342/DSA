// LEETCODE 1524

class Solution {
    public:
        const int MOD = 1e9 + 7;
        int numOfSubarrays(vector<int>& arr) {
            int count = 0;
            int prefixSum = 0;
    
            int oddCount = 0;
            int evenCount = 1;
    
            for(auto num : arr){
                prefixSum += num;
    
                if(prefixSum%2 == 0){
                    count += oddCount;
                    evenCount++;
                }
                else{
                    count += evenCount;
                    oddCount++;
                }
    
                count %= MOD;
            }
            return count%MOD;
        }
    };