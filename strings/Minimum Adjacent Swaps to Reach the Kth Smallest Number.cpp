// LEETCODE 1850

class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.length();
        string temp = num;

        while(k--){
            next_permutation(temp.begin(), temp.end());
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(num[i] != temp[i]){
                int j = i + 1;
                while(num[j] != temp[i]){
                    j++;
                }

                while(j > i){
                    swap(num[j], num[j-1]);
                    j--;
                    ans++;
                }
            }
        }
        return ans;
    }
};