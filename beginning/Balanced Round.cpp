// CODEFORCES 900 RATED

#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define nl '\n'
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        ll n,k;
        cin>>n>>k;
    
        vi arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
    
        sort(arr.begin(), arr.end());
    
        int l = 1, cnt=1;
        //a1 a2 a3 a4
        for(int i=1; i<n; i++){
            if(arr[i] - arr[i-1] <= k)
                cnt++;
            else
                cnt = 1;
    
            l = max(cnt, l);
        }
    
        cout<<n-l<<nl;
    }

    return 0;
}