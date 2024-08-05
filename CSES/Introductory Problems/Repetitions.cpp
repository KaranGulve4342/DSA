// EVERY PROBLEM IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    string str;
    cin >> str;
    int n = str.length();
    int ans = 1;
    int count = 1;

    for(int i = 1;i < n;i++){
        if(str[i] == str[i-1]){
            count++;
        }
        else{
            count = 1;
        }
        ans = max(count, ans);
    }

    cout<<ans<<endl;
    return 0;
}