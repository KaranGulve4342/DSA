// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;  i < n; i++){
        cin >> a[i];
    }

    int count = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(a[i] == a[n-1]){
            count++;
        }
    }
    if(a[0] == a[n-1]){
        cout << -1 << endl;
        return;
    }
    cout<<n-count<<" "<<count<<endl;
    for(int i = 0; i < n-count; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < count; i++){
        cout << a[n-1] << " ";
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}