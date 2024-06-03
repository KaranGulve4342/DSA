// CODEFORCES 800 RATED

#include <bits/stdc++.h>    
using namespace std;

int solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 0;
    int ans = 2;

    bool flag = false;
    for(int i = 0;i < n;i++){
        if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.' && i+2 < n){
            flag = true;
        }
        if(s[i] == '.'){
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