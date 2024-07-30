// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define line cout << "\n";
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);


void solve () {
    ll n;
    cin >> n;
    ll a[n];
    ll neg = 0;
    ll prevsum =0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] < 0) {
            neg++;
        }
    }
    ll plusmesabsechhota = 1e9;
    for(int i=0; i<n; i++) {

        if(plusmesabsechhota > abs(a[i])) {
            plusmesabsechhota = abs(a[i]);
        }
    }
    for(int i=0; i<n; i++) {
        prevsum += abs(a[i]);
    }
    if(neg == 0) {
        cout << prevsum; line
        return;
    }
    // cout << plusmesabsechhota <<" ";
    if(neg % 2 != 0) {
        prevsum -= (2*plusmesabsechhota);
    }
    // cout << prevsum <<" " ;
    cout <<  prevsum; line;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while(t--) {
        solve();
        // clear_global();
    }
    // solve();
    return 0;
}