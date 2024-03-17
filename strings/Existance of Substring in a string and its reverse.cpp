// LEETCODE 3083

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> uset;
        for(int i = 0; i < s.length() - 1; i++){
            string temp = s.substr(i, 2);
            uset.insert(temp);
            string rev = temp;
            reverse(rev.begin(), rev.end());
            if (uset.count(rev)){
                return true;
            }
        }
        return false;
    }
};