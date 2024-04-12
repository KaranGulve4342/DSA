#include<bits/stdc++.h>
using namespace std;
 
int solve(){
    int n;
    cin >> n;
    string str;
    cin >>  str;
    
    int count = 0;
    int ans = 2;
    bool flag = false;
    for(int i = 0;i < n;i++){
        if(str[i] == '.' && i+2 < n && str[i+1] == '.' && str[i+2] == '.'){
            flag = true;
        }
        if(str[i] == '.'){
            count++;
        }
    }
    
    if(!flag) ans = count;
    
    return ans;
}
 
int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}
