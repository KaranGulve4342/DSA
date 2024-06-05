// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        int c;
        cin >> c;
        cout<<n-c+1<<" ";
    }
    cout<<endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }
}