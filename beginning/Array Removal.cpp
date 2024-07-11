#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(vector<ll>& arr, ll k, ll n) {
    
    long long ans = 0;
    ll curr = 0;
    ll count = 0;

    for (ll i = 0;i < n;i++) {
        if (arr[i] > k) {
            continue;
        }

        count++;
        curr |= ele;
    }

    if (curr == k) {
        ans = n - count;
    } 
    else {
        ans = n;
    }
    
    return ans;
}

ll karan(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    
    ll mini = n;

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    
    for (ll i = 0; i < 32; i++) {

        ll targetValue = (1 << i);

        mini = min(mini, solve(arr, targetValue-1, n));
    
    }
    return mini;
}

int main() {
    ll T;
    cin >> T;
    
    while (T--) {
        cout<<karan()<<endl;
    }
    
    return 0;
}