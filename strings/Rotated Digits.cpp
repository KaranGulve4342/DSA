// LEETCODE 788

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 0;i <= n;i++){
            string str = to_string(i);

            if(str.find("3") != string::npos) continue;
            if(str.find("4") != string::npos) continue;
            if(str.find("7") != string::npos) continue;


            if(str.find("2") != string::npos || 
                str.find("5") != string::npos || 
                str.find("6") != string::npos || 
                str.find("9") != string::npos){
                count++;
            }
        }
        return count;

    }
};