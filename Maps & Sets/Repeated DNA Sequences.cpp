// LEETCODE 187

/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length() < 10){
            return ans;
        }
        unordered_map<string, int> sequenceCount;
        for(int i = 0;i <= s.length()-10;i++){
            string str = s.substr(i,10);

            if(sequenceCount.find(str) == sequenceCount.end()){
                sequenceCount[str] = 1;
            }
            else{
                sequenceCount[str]++;
            }


            if(sequenceCount[str] == 2){
                ans.push_back(str);
            }
        }
        return ans; 
    }
};
*/