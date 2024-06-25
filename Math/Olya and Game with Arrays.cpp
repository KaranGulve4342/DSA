// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INT_MAX LLONG_MAX

int solve(){
    int m;
    cin >> m;
    int a = 0;
    int b = INT_MAX;
    int c = INT_MAX;

    while(m--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        a += arr[1];
        b = min(arr[0], b);
        c = min(arr[1], c);
    }

    return a+b-c;
    
    
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}