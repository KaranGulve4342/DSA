// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, k, b, s;
    cin >> n >> k;
    cin >> b >> s;

    if(s < k*b || s > (k*b + (k-1)*n)){
        cout<<-1<<endl;
        return;
    }

    vector<long long> a(n, 0);

    a[0] = k*b;
    s -= k*b;

    for(int i = 0;i < n;i++){
        long long x = min(k-1, s);
        a[i] += x;
        s -= x;
    }

    for(auto it : a){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}