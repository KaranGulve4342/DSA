// LEETCODE 1239 POTD 23 JAN 2024

class Solution {
public:
    void backTrack(vector<string>&arr, string current, int start, int &maxLength){
        if(maxLength < current.length()){
            maxLength = current.length();
        }

        for(int i = start;i < arr.size();i++){
            if(!isValid(current, arr[i])){
                continue;
            }

            backTrack(arr, current + arr[i], i+1, maxLength);
        }
    }
    bool isValid(string &current, string &newString){
        unordered_set<char> charSet;
        for(char ch : newString){
            if(charSet.count(ch) > 0){
                return false;
            }

            charSet.insert(ch);

            if(current.find(ch) != string::npos){
                return false;
            }
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int maxLength = 0;

        backTrack(arr, "", 0, maxLength);
        return maxLength;
    }
};