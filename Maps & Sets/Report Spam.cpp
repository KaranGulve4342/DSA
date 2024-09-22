// LEETCODE 3295

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> uset(bannedWords.begin(), bannedWords.end());

        int count = 0;

        for(auto msg : message){
            if(uset.find(msg) != uset.end()){
                count++;
            }

            if(count > 1){
                return true;
            }
        }
        return false;

    }
};