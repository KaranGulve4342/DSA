// LEETCODE 481

class Solution {
public:
    int magicalString(int n) {
        
        string str = "122";
        int i = 2;
        
        while(str.size()<n){
            
            if(str[i]=='2'){
                if(str.back()=='1'){
                    str+="22";
                }
                else{
                    str+="11";
                }
            }
            else{
                if(str.back()=='2'){
                    str+='1';
                }
                else{
                    str+='2';
                }    
            }
            
            i++;
        }
        
        
        if(str.size()==n+1){
            str.pop_back();
        }
        
        int ans = 0;
        
        for(auto iter : str){
            if(iter=='1') ans++;
        }
        
        return ans;
    }
};