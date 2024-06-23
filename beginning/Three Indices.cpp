// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2;i < n;i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            cout << "YES" << endl;
            cout << i-1 << " " << i << " " << i+1 << endl;
            return;
        }
    }
    cout << "NO" << endl;

}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}