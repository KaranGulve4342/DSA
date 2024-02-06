// LEETCODE 202

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        int idx;
        int val;

        while(true){
            int val = 0;
            while(n > 0){
                idx = n%10;
                val += (idx * idx);
                n /= 10;
            }
            if(val == 1){
                return true;
            }
            else if(uset.find(val) != uset.end()){
                return false;
            }
            else{
                uset.insert(val);
                n = val;
            }
        }
    }
};