// LEETCODE 670

class Solution {
public:
    int getMax(string s, int i){
        int maxi=i;
        for(int j = i;j < s.length();j++){
            if(s[maxi] <= s[j]){
                maxi = j;
            }
        }
        return maxi;
    }
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();

        string s = str;

        for(int i = 0;i < n;i++){
            int temp = getMax(s, i);

            swap(s[i], s[temp]);

            if(s != str){
                break;
            }
        }
        int ans = stoi(s);
        return ans;
    }
};