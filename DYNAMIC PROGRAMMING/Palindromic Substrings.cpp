// LEETCODE 647

/*
class Solution{
    int check(string s, int i, int j){
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s){
        int count = 0;
        for(int i = 0;i < s.length();i++){
            int even = check(s, i, i);
            int odd = check(s, i, i+1);

            count += even + odd;
        }
        return count;

    }
}
*/